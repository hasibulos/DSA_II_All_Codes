#include <bits/stdc++.h>

using namespace std;

int main()

{

    int n;

    cout << "Enter the length of the rod: ";

    cin >> n;

    int p[n];

    cout << "Enter the profit: ";

    for (int i = 0; i < n; i++)

    {

        cin >> p[i];
    }

    int dp[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++)

    {

        dp[i] = INT_MIN;

        for (int j = 0; j < i; j++)

        {

            dp[i] = max(dp[i], p[j] + dp[i - j - 1]);
        }
    }

    cout << "Maximum profit: " << dp[n] << endl;

    return 0;
}
