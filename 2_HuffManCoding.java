import java.util.*;

public class HuffmanCoding {
    private static class Node implements Comparable<Node> {
        char ch;
        int freq;
        Node left, right;

        Node(char c, int f) {
            ch = c;
            freq = f;
            left = right = null;
        }

        @Override
        public int compareTo(Node other) {
            return this.freq - other.freq;
        }
    }

    public void printCodes(Node root, String code) {
        if (root == null)
            return;

        // Leaf node
        if (root.left == null && root.right == null) {
            System.out.println(root.ch + " : " + code);
        }

        printCodes(root.left, code + "0");
        printCodes(root.right, code + "1");
    }

    public void huffmanCoding(char[] ch, int[] freq, int n) {
        PriorityQueue<Node> pq = new PriorityQueue<>();

        // Create leaf nodes
        for (int i = 0; i < n; i++) {
            pq.add(new Node(ch[i], freq[i]));
        }

        // Build Huffman Tree
        while (pq.size() > 1) {
            Node left = pq.poll();
            Node right = pq.poll();

            Node newNode = new Node('$', left.freq + right.freq);
            newNode.left = left;
            newNode.right = right;

            pq.add(newNode);
        }

        // Root of tree
        Node root = pq.poll();

        System.out.println("\nHuffman Codes:");
        printCodes(root, "");
    }

    public static void main(String[] args) {
        HuffmanCoding h = new HuffmanCoding();
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of characters: ");
        int n = sc.nextInt();

        char[] ch = new char[n];
        int[] freq = new int[n];

        System.out.println("\nEnter characters and frequencies:");
        for (int i = 0; i < n; i++) {
            ch[i] = sc.next().charAt(0);
            freq[i] = sc.nextInt();
        }

        h.huffmanCoding(ch, freq, n);

        sc.close();
    }
}
