#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int n, amount;

    cout << "Enter number of coins: ";
    cin >> n; // কয়টি coin denomination

    int coins[n];
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i]; // coin values ইনপুট

    cout << "Enter amount: ";
    cin >> amount; // target amount

    int dp[n + 1][amount + 1]; // DP table (coins+1)*(amount+1)

    // --------------------------
    // DP table fill করা
    // --------------------------
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (j == 0)
                dp[i][j] = 0; // 0 amount → 0 coins needed
            else if (i == 0)
                dp[i][j] = INT_MAX - 1; // 0 coins → INF (impossible)
            else if (coins[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            // coin বড় → ব্যবহার করা যাবে না
            else
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            // coin না নিলে আগের value, নিলে 1 + dp[remaining]
        }
    }

    if (dp[n][amount] == INT_MAX - 1)
        cout << "Not possible\n";
    else
        cout << "Minimum coins needed: " << dp[n][amount] << endl;

    // --------------------------
    // Backtracking to find coins used
    // --------------------------
    cout << "Coins used: ";
    int i = n, j = amount;
    while (j > 0 && i > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        { // coin i used
            cout << coins[i - 1] << " ";
            j -= coins[i - 1]; // reduce remaining amount
        }
        else
        {
            i--; // check smaller coin
        }
    }
    cout << endl;
}
