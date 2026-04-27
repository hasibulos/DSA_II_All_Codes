#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements (sorted): ";
    cin >> n;
    int a[100];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k = 0; // next write position
    for (int i = 0; i < n; i++)
    {
        if (k == 0 || a[i] != a[k - 1])
        {
            a[k] = a[i];
            k++;
        }
    }
    cout << "Cleaned list: ";
    for (int i = 0; i < k; i++)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}
