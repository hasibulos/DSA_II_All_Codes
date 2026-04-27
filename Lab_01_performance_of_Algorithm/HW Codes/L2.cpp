#include <iostream>
using namespace std;
int main()
{

    int ara[10], n, x, i;
    cout << "Enter the number of elements Size (max 10): ";
    cin >> n;

    cout << "Enter the Array elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> ara[i];
    }

    cout << "Enter the element to insert at Beginning: ";
    cin >> x;

    for (i = n; i > 0; i--)
    {
        ara[i] = ara[i - 1];
    }

    ara[0] = x;
    n++;

    cout << "Array after Insertion: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << ara[i] << endl;
    }

    return 0;
}
