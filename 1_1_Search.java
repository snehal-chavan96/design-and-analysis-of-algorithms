import java.util.Scanner;
import java.util.Random;

public class Search {
    private int[] arr = new int[100];
    private int n;
    private Scanner sc = new Scanner(System.in);
    private Random rand = new Random();

    public void getData() {
        System.out.print("Enter number of elements: ");
        n = sc.nextInt();

        System.out.println("Enter sorted elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public void linearSearch(int key) {
        for (int i = 0; i < n; i++) {
            System.out.println("\nFinding element " + key + " at pos " + (i + 1));
            if (arr[i] == key) {
                System.out.println("Element found at position " + (i + 1) + " using Linear Search");
                return;
            }
        }
        System.out.println("Element not found using Linear Search");
    }

    public void binarySearch(int key) {
        int low = 0, high = n - 1, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            System.out.println("\nFinding element " + key + " at pos " + (mid + 1));

            if (arr[mid] == key) {
                System.out.println("Element found at position " + (mid + 1) + " using Binary Search");
                return;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println("Element not found using Binary Search");
    }

    public void modifiedBinarySearch(int key) {
        int low = 0, high = n - 1, mid;

        while (low <= high) {
            mid = low + rand.nextInt(high - low + 1);
            System.out.println("\nFinding element " + key + " at pos " + (mid + 1));

            if (arr[mid] == key) {
                System.out.println("Element found at position " + (mid + 1) + " using Modified Binary Search");
                return;
            } else if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        System.out.println("Element not found using Modified Binary Search");
    }

    public static void main(String[] args) {
        Search s = new Search();
        Scanner sc = new Scanner(System.in);

        s.getData();

        System.out.print("Enter element to search: ");
        int key = sc.nextInt();

        System.out.println("\n--- Linear Search ---");
        s.linearSearch(key);

        System.out.println("\n--- Binary Search ---");
        s.binarySearch(key);

        System.out.println("\n--- Modified Binary Search ---");
        s.modifiedBinarySearch(key);

        sc.close();
    }
}
