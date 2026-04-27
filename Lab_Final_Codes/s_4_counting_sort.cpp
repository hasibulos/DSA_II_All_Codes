#include <bits/stdc++.h>
using namespace std;

// Counting Sort function
void countingSort(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return; // যদি array খালি → কিছু করা লাগবে না

    // Step 1: Find maximum element
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i]; // max element বের করা

    // Step 2: Initialize count array
    vector<int> count(maxVal + 1, 0); // সব 0 দিয়ে শুরু

    // Step 3: Count occurrences
    for (int i = 0; i < n; i++)
        count[arr[i]]++; // প্রতিটি element কতবার আছে গোনা

    // Step 4: Cumulative count (position info)
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Step 5: Build output array
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i]; // correct position এ রাখো
        count[arr[i]]--;                    // next duplicate জন্য কমাও
    }

    // Step 6: Copy sorted array back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
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

    countingSort(arr); // sort call

    cout << "Sorted Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
