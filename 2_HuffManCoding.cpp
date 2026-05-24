#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Huffman
{
    struct Node
    {
        char ch;
        int freq;
        Node *left, *right;

        Node(char c, int f)
        {
            ch = c;
            freq = f;
            left = right = NULL;
        }
    };

    // Comparator for priority queue
    struct compare
    {
        bool operator()(Node* l, Node* r)
        {
            return l->freq > r->freq;
        }
    };

public:

    // Print Huffman Codes
    void printCodes(Node* root, string code)
    {
        if(root == NULL)
            return;

        // Leaf node
        if(root->left == NULL &&
           root->right == NULL)
        {
            cout << root->ch
                 << " : "
                 << code << endl;
        }

        printCodes(root->left, code + "0");

        printCodes(root->right, code + "1");
    }

    // Huffman Algorithm
    void huffmanCoding(char ch[],
                        int freq[],
                        int n)
    {
        priority_queue<Node*,
                       vector<Node*>,
                       compare> pq;

        // Create leaf nodes
        for(int i = 0; i < n; i++)
        {
            pq.push(new Node(ch[i], freq[i]));
        }

        // Build Huffman Tree
        while(pq.size() != 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *newNode =
            new Node('$',
                     left->freq + right->freq);

            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        // Root of tree
        Node *root = pq.top();

        cout << "\nHuffman Codes:\n";

        printCodes(root, "");
    }
};

int main()
{
    Huffman h;

    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char ch[100];
    int freq[100];

    cout << "\nEnter characters and frequencies:\n";

    for(int i = 0; i < n; i++)
    {
        cin >> ch[i] >> freq[i];
    }

    h.huffmanCoding(ch, freq, n);

    return 0;
}

