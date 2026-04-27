#include <iostream>
using namespace std;

int sumRec(int a[], int n)
{
    if (n == 0)
        return 0;
    return a[n - 1] + sumRec(a, n - 1);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Sum = " << sumRec(a, n) << "\n";
    return 0;
}
