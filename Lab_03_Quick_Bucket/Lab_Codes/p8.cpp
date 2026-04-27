#include <iostream>
using namespace std;

int firstOcc(int a[], int n, int x)
{
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == x)
        {
            ans = m;
            r = m - 1;
        }
        else if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int lastOcc(int a[], int n, int x)
{
    int l = 0, r = n - 1, ans = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (a[m] == x)
        {
            ans = m;
            l = m + 1;
        }
        else if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return ans;
}

int main()
{
    int n, x;
    cout << "Enter number of elements (sorted): ";
    cin >> n;
    int ids[100];
    cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++)
        cin >> ids[i];
    cout << "Enter ID to find: ";
    cin >> x;
    int f = firstOcc(ids, n, x);
    int g = lastOcc(ids, n, x);
    if (f == -1)
        cout << "ID not found\n";
    else
        cout << "First index = " << f << ", Last index = " << g << "\n";
    return 0;
}
