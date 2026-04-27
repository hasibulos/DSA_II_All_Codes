#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, s;

    cout << "Enter number of coins: ";

    cin >> n;

    int v[n];

    cout << "Enter the coin denominations: ";

    for (int i = 0; i < n; i++) {

        cin >> v[i];

    }

    cout << "Enter the sum: ";

    cin >> s;

    int dp[n + 1][s + 1];


    for (int i = 0; i <= n; i++) {

        for (int j = 0; j <= s; j++) {

            if (j == 0) {

                dp[i][j] = 0;
            } else if (i == 0) {

                dp[i][j] = INT_MAX - 1;
            } else {

                if (v[i - 1] <= j) {

                    if (dp[i][j - v[i - 1]] != INT_MAX - 1)

                        dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - v[i - 1]]);

                    else

                        dp[i][j] = dp[i - 1][j];

                } else {

                    dp[i][j] = dp[i - 1][j];
                }

            }

        }

    }


    if (dp[n][s] == INT_MAX - 1) {

        cout << "It's not possible to make the sum with the given coins." << endl;

    } else {

        cout << "Minimum number of coins required: " << dp[n][s] << endl;

    }

    return 0;

}


