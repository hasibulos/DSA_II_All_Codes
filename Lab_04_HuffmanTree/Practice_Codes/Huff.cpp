#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char character;
    int frequency;
    Node *left;
    Node *right;
    Node(char c, int f)
    {
        character = c;
        frequency = f;
        left = right = nullptr;
    }
};

struct CompareFreq
{
    bool operator()(Node *a, Node *b)
    {
        return a->frequency > b->frequency;
    }
};

Node *createHuffmanTree(vector<pair<char, int>> &freqList)
{
    priority_queue<Node *, vector<Node *>, CompareFreq> pq;
    for (auto &p : freqList)
        pq.push(new Node(p.first, p.second));

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('$', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }
    return pq.top();
}

void generateCodes(Node *root, string code,
                   unordered_map<char, string> &codeMap,
                   unordered_map<char, int> &freqMap,
                   int &totalHuffmanBits)
{
    if (!root)
        return;

    if (root->character != '$')
    {
        codeMap[root->character] = code;
        totalHuffmanBits += freqMap[root->character] * code.size();
    }

    generateCodes(root->left, code + "0", codeMap, freqMap, totalHuffmanBits);
    generateCodes(root->right, code + "1", codeMap, freqMap, totalHuffmanBits);
}

int main()
{
    int n;
    cout << "Enter string size: ";
    cin >> n;

    string input;
    cout << "Enter the string: ";
    cin >> input;

    if (input.size() != n)
    {
        cout << "Warning: Given size does not match string length!\n";
    }

    unordered_map<char, int> freqMap;
    for (char c : input)
    {
        freqMap[c]++;
    }

    vector<pair<char, int>> freqList(freqMap.begin(), freqMap.end());

    Node *root = createHuffmanTree(freqList);

    unordered_map<char, string> codeMap;
    int totalHuffmanBits = 0;
    generateCodes(root, "", codeMap, freqMap, totalHuffmanBits);

    int totalChars = input.size();
    int normalBits = totalChars * 8;

    cout << "\nCharacter Frequencies:\n";
    for (auto &p : freqMap)
    {
        cout << p.first << " : " << p.second << "\n";
    }

    cout << "\nHuffman Codes for each character:\n";
    for (auto &p : codeMap)
    {
        cout << p.first << " : " << p.second << "\n";
    }

    cout << "\nNormal Encoding Bits (8-bit fixed): " << normalBits;
    cout << "\nHuffman Encoding Bits: " << totalHuffmanBits;
    cout << "\nCompression Ratio = " << normalBits << ":" << totalHuffmanBits;

    if (totalHuffmanBits < normalBits)
    {
        double ratio = (double)normalBits / totalHuffmanBits;
        cout << "\nAbout " << fixed << setprecision(2) << ratio << " : 1 compression\n";
    }
    else
    {
        cout << "\nNo compression (Huffman is larger or equal)\n";
    }

    return 0;
}
