#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) cin >> coins[i];

    cout << "Enter target sum: ";
    cin >> sum;

    const int INF = 1e9;
    vector<int> dp(sum + 1, INF);
    vector<int> choice(sum + 1, -1);

    dp[0] = 0; // Base case

    // Step 1: Build dp and choice table
    for (int i = 1; i <= sum; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] + 1 < dp[i]) {
                dp[i] = dp[i - coin] + 1;
                choice[i] = coin;
            }
        }
    }

    // Step 2: Print dp and choice arrays
    cout << "\ndp:      ";
    for (int i = 0; i <= sum; i++) cout << dp[i] << " ";
    cout << "\nchoice:  ";
    for (int i = 0; i <= sum; i++) cout << choice[i] << " ";
    cout << "\n";

    // Step 3: Reconstruction (coins used)
    vector<int> usedCoins;
    int cur = sum;
    while (cur > 0 && choice[cur] != -1) {
        int c = choice[cur];
        usedCoins.push_back(c);
        cur -= c;
    }

    // Step 4: Output result
    if (dp[sum] == INF)
        cout << "\nNo solution possible for the given sum.\n";
    else {
        cout << "\nMinimum coins needed = " << dp[sum] << endl;
        cout << "Coins used: ";
        for (int c : usedCoins) cout << c << " ";
        cout << endl;
    }

    return 0;
}
