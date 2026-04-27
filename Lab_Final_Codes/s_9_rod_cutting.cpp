#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter rod length: ";
    cin >> n; // rod length

    int price[n + 1]; // price[i] = profit of rod length i
    cout << "Enter prices for each length: ";
    for (int i = 1; i <= n; i++)
        cin >> price[i]; // price input

    int dp[n + 1][n + 1]; // DP table (length+1)*(rod length+1)

    // --------------------------
    // DP table fill করা
    // --------------------------
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // rod length 0 বা i=0 → profit 0
            else if (i > j)
                dp[i][j] = dp[i - 1][j];
            // rod length i > current length j → cut না করা
            else
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i][j - i]);
            // না কাটলে আগের value, কাটলে price[i] + বাকি rod এর profit
        }
    }

    cout << "Maximum Profit: " << dp[n][n] << endl;

    // --------------------------
    // Backtracking to find rod lengths cut
    // --------------------------
    cout << "Rod lengths cut: ";
    int i = n, j = n;
    while (j > 0 && i > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {                     // rod length i cut হয়েছে
            cout << i << " "; // print rod length
            j -= i;           // reduce remaining length
        }
        else
        {
            i--; // check smaller rod length
        }
    }
    cout << endl;
}
