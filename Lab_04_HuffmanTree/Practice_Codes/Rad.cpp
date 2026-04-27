#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortAscending(vector<int> &arr)
{
    int maxVal = arr[0];
    for (int val : arr)
        if (val > maxVal)
            maxVal = val;

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    vector<int> arr;
    int n, x;
    cout << "Enter number of n: ";
    cin >> n;
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    radixSortAscending(arr);

    cout << "Sorted Array : ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
    return 0;
}
