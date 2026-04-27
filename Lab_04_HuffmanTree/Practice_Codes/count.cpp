#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return;

    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    vector<int> count(maxVal + 1, 0);

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

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

