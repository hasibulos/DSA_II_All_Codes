#include <iostream>
using namespace std;
int main()
{

    int ara[10], n, x, i;
    cout << "Enter the number of elements Size (max 10): ";
    cin >> n;
    cout << "Enter the number of Array elements : ";
    for (i = 0; i < n; i++)
    {
        cin >> ara[i];
    }
    cout << "Enter the element of insert at End : ";
    cin >> x;
    ara[i] = x;
    n++;
    for (int i = 0; i < n; i++)
    {
        cout << ara[i] << endl;
    }

    return 0;
}
