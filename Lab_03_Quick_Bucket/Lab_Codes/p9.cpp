#include <iostream>
using namespace std;

void swapStr(string &a, string &b)
{
    string t = a;
    a = b;
    b = t;
}

int partitionArr(string a[], int low, int high)
{
    string pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swapStr(a[i], a[j]);
        }
    }
    swapStr(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(string a[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionArr(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of names: ";
    cin >> n;
    string names[100];
    cout << "Enter names: ";
    for (int i = 0; i < n; i++)
        cin >> names[i];
    cout << "Before: ";
    for (int i = 0; i < n; i++)
        cout << names[i] << " ";
    cout << "\n";
    quickSort(names, 0, n - 1);
    cout << "After: ";
    for (int i = 0; i < n; i++)
        cout << names[i] << " ";
    cout << "\n";
    return 0;
}
