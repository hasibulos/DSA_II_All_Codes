#include <iostream>
using namespace std;

void printRevInt(int a[], int i)
{
    if (i < 0)
        return;
    cout << a[i] << " ";
    printRevInt(a, i - 1);
}

void printRevStr(string a[], int i)
{
    if (i < 0)
        return;
    cout << a[i] << " ";
    printRevStr(a, i - 1);
}

int main()
{
    int n1, n2;
    cout << "Enter number of integers: ";
    cin >> n1;
    int nums[100];
    cout << "Enter integers: ";
    for (int i = 0; i < n1; i++)
        cin >> nums[i];
    cout << "Enter number of strings: ";
    cin >> n2;
    string names[100];
    cout << "Enter strings: ";
    for (int i = 0; i < n2; i++)
        cin >> names[i];
    cout << "Reversed ints: ";
    printRevInt(nums, n1 - 1);
    cout << "\nReversed strings: ";
    printRevStr(names, n2 - 1);
    cout << "\n";
    return 0;
}
