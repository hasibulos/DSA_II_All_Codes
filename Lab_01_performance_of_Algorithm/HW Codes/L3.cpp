#include <iostream>
using namespace std;
int main()
{

    int ara[20], n, x, pos, i;
    cout << "Enter the number of elements Size (max 20): ";
    cin >> n;

    cout << "Enter the Array elements: ";
    for (i = 0; i < n; i++)
    {
        cin >> ara[i];
    }

    cout << "Enter the element to insert: ";
    cin >> x;

    cout << "Enter the position (0 to " << n << "): ";
    cin >> pos;

    if (pos < 0 || pos > n)
    {
        cout << "Invalid Position!" << endl;
        return 0;
    }

    for (i = n; i > pos; i--)
    {
        ara[i] = ara[i - 1];
    }

    ara[pos] = x;
    n++;

    cout << "Array after Insertion: " << endl;
    for (i = 0; i < n; i++)
    {
        cout << ara[i] << " ";
    }
    cout << endl;

    return 0;
}
