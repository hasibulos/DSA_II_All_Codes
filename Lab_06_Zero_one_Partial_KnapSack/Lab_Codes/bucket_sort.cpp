#include <bits/stdc++.h>
using namespace std;
/*  Here start the bucket sort code implementation but first we start step 1 and
    step 2 then step 3 function below(insertion sort)
    then step 1-4 function (bucket sort) and finally main function   */

// Step 3: Per bucket insertion sort function
void insertionSort(vector<int> &bucket)
{
    for (int i = 1; i < bucket.size(); i++)
    {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Step 1-4: Bucket sort function
void bucketSort(int arr[], int n)
{
    if (n <= 0)
        return;

    // Step 1: Max, Min ber kora
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // Step 2: Create n empty buckets
    vector<int> buckets[n];

    // Step 2: Distribute elements using index formula
    for (int i = 0; i < n; i++)
    {
        int index = floor((double)(arr[i] - min) / (max - min) * n);
        if (index == n)
            index = n - 1; // max element edge case(that's mean maximum element out of bucket range and we force it to be in last bucket)
        buckets[index].push_back(arr[i]);
    }

    // Step 3: Sort each bucket using insertion sort
    for (int i = 0; i < n; i++)
    {
        insertionSort(buckets[i]);
    }

    // Step 4: Merge all buckets
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[k++] = buckets[i][j];
        }
    }
}

int main()
{
    // User input
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call bucket sort
    bucketSort(arr, n);

    // Step 5: Final array print
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
