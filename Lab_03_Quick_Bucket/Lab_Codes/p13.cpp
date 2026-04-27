#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter n (<=30): ";
    if (!(cin >> n) || n < 1 || n > 30)
    {
        cout << "Invalid n\n";
        return 0;
    }
    int prev[31], curr[31];
    for (int i = 0; i < n; i++)
    {
        int len = i + 1;
        for (int sp = 0; sp < (n - 1 - i); sp++)
        {
            cout << " ";
        }
        for (int j = 0; j < len; j++)
        {
            if (j == 0 || j == len - 1)
                curr[j] = 1;
            else
                curr[j] = prev[j - 1] + prev[j];
        }
        for (int j = 0; j < len; j++)
            cout << curr[j] << " ";
        cout << "\n";
        for (int j = 0; j < len; j++)
            prev[j] = curr[j];
    }
    return 0;
}
