#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return;

    // Find maximum element
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // Initialize count array
    vector<int> count(maxVal + 1, 0);

    // Store count of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Modify count array to store cumulative count
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Build output array
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy sorted array back to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    countingSort(arr);

    cout << "Sorted Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
