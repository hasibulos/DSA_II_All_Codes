#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of prices (sorted): ";
    cin >> n;
    double price[100];
    cout << "Enter sorted prices: ";
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << "Enter new price: ";
    double p;
    cin >> p;
    int pos = n;
    for (int i = 0; i < n; i++)
    {
        if (p < price[i])
        {
            pos = i;
            break;
        }
    }
    for (int i = n; i > pos; i--)
        price[i] = price[i - 1];
    price[pos] = p;
    n++;
    cout << "Updated prices: ";
    for (int i = 0; i < n; i++)
        cout << price[i] << " ";
    cout << "\n";
    return 0;
}
