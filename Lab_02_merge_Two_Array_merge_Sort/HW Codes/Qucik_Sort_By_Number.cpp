#include <iostream>
#include <vector>
using namespace std;

// Partition function for integers
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "Pivot " << pivot << " placed: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return i + 1;
}

// Quick Sort recursive function
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nOriginal Numbers: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl
         << endl;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted Numbers: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
