#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of product IDs (sorted): ";
    cin >> n;
    int ids[100];
    cout << "Enter sorted product IDs: ";
    for (int i = 0; i < n; i++)
        cin >> ids[i];
    cout << "Enter product ID to search: ";
    int x;
    cin >> x;
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (ids[m] == x)
        {
            ans = m;
            break;
        }
        else if (ids[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    if (ans == -1)
        cout << "Product not in inventory\n";
    else
        cout << "Found at index " << ans << "\n";
    return 0;
}
