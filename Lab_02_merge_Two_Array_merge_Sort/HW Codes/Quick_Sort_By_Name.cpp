#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Partition function for strings
int partition(vector<string> &arr, int low, int high)
{
    string pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        { // lexicographical order
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    cout << "Pivot \"" << pivot << "\" placed: ";
    for (string s : arr)
        cout << s << " ";
    cout << endl;

    return i + 1;
}

// Quick Sort recursive function
void quickSort(vector<string> &arr, int low, int high)
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
    cout << "Enter number of names: ";
    cin >> n;

    vector<string> names(n);
    cout << "Enter names: ";
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    cout << "\nOriginal Names: ";
    for (string s : names)
        cout << s << " ";
    cout << endl
         << endl;

    quickSort(names, 0, n - 1);

    cout << "\nSorted Names: ";
    for (string s : names)
        cout << s << " ";
    cout << endl;

    return 0;
}
