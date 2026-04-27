#include <bits/stdc++.h>
using namespace std;

// Counting sort used for Radix Sort (digit-wise)
void countingSortForRadix(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0}; // digits 0-9

    // Step 1: Count occurrences of each digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Step 2: Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Step 3: Build output array (stable)
    for (int i = n - 1; i >= 0; i--)
    {
        int idx = (arr[i] / exp) % 10;
        output[count[idx] - 1] = arr[i];
        count[idx]--;
    }

    // Step 4: Copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort function
void radixSort(vector<int> &arr)
{
    int maxVal = *max_element(arr.begin(), arr.end());

    // Step 5: Sort by each digit place
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortForRadix(arr, exp);
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

    radixSort(arr); // sort call

    cout << "Sorted Array: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}
