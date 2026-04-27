#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node
{
    float data;
    Node *next;
    Node(float val) : data(val), next(NULL) {}
};

// Sorted Insertion in Linked List
void sortedInsert(Node *&head, float val)
{
    Node *newNode = new Node(val);
    if (!head || head->data >= val)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next && temp->next->data < val)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void bucketSort(vector<float> &arr)
{
    int n = arr.size();
    if (n <= 0)
        return;

    float minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    vector<Node *> buckets(n, NULL);

    // Distribute elements into buckets
    for (int i = 0; i < n; i++)
    {
        int index = floor(((arr[i] - minVal) / (maxVal - minVal)) * (n - 1));
        sortedInsert(buckets[index], arr[i]);
    }

    // Merge buckets back to array
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        Node *curr = buckets[i];
        while (curr)
        {
            arr[k++] = curr->data;
            curr = curr->next;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (float x : arr)
        cout << x << " ";
    cout << endl;

    bucketSort(arr);

    cout << "Sorted Array: ";
    for (float x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}

// 1. প্রতিটি bucket linked list আকারে থাকে
//     Array -এর element কে bucket index অনুযায়ী allocate করা হয়।
//     প্রতিটি bucket linked list হিসেবে তৈরি হয়।
//     sortedInsert() function ব্যবহার করলে element ঢুকার সময়েই bucket sorted হয়ে যায়।

// 2. Linked list traverse করে প্রতিটা node array তে copy করা হচ্ছে
// প্রতিটি bucket linked list traverse করা হয়।
// প্রতিটি node- এর value sequentially array arr তে copy করা হয়।

// 3.সব bucket merge হলে final sorted array পাওয়া যায় সব bucket traverse হয়ে array তে copy হয়ে গেলে,
// array পুরোপুরি sorted হয়ে যায়।