#include <bits/stdc++.h>
using namespace std;

// Bucket Sort function
void bucketSort(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return; // empty array check

    // Step 1: Find max and min
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int bucketCount = n; // bucket count = number of elements
    double range = (double)(maxVal - minVal + 1) / bucketCount;

    vector<vector<int>> buckets(bucketCount); // create buckets

    // Step 2: Put elements into buckets
    for (int i = 0; i < n; i++)
    {
        int idx = (int)((arr[i] - minVal) / range); // bucket index
        if (idx == bucketCount)
            idx--;                      // edge case
        buckets[idx].push_back(arr[i]); // add to bucket
    }

    // Step 3: Sort each bucket individually
    for (int i = 0; i < bucketCount; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // Step 4: Concatenate all buckets
    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int val : buckets[i])
            arr[index++] = val; // sorted array তে বসানো
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bucketSort(arr); // sort call

    cout << "Sorted Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
