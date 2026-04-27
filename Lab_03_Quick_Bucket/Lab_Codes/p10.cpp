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
    cout << "Enter target sum: ";
    int target;
    cin >> target;
    int i = 0, j = n - 1;
    while (i < j)
    {
        int s = a[i] + a[j];
        if (s == target)
        {
            cout << "Pair: " << a[i] << " + " << a[j] << " = " << target << "\n";
            return 0; // found; exit program
        }
        else if (s < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout << "No pair found\n";
    return 0;
}
