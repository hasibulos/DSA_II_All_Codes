#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter rod length: ";
    cin >> n;

    vector<int> price(n + 1);
    cout << "Enter prices for each length (1 to " << n << "): ";
    price[0] = 0; // For convenience
    for (int i = 1; i <= n; i++) cin >> price[i];

    const int NEG_INF = -1e9;
    vector<int> dp(n + 1, NEG_INF);
    vector<int> choice(n + 1, -1);

    dp[0] = 0; // Base case

    // Step 1: Build dp and choice table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (price[j] + dp[i - j] > dp[i]) {
                dp[i] = price[j] + dp[i - j];
                choice[i] = j;
            }
        }
    }

    // Step 2: Print dp and choice arrays
    cout << "\ndp:      ";
    for (int i = 0; i <= n; i++) cout << dp[i] << " ";
    cout << "\nchoice:  ";
    for (int i = 0; i <= n; i++) cout << choice[i] << " ";
    cout << "\n";

    // Step 3: Reconstruction (cut lengths)
    vector<int> cuts;
    int cur = n;
    while (cur > 0 && choice[cur] != -1) {
        int cut = choice[cur];
        cuts.push_back(cut);
        cur -= cut;
    }

    // Step 4: Output result
    cout << "\nMaximum profit = " << dp[n] << endl;
    cout << "Cuts used: ";
    for (int c : cuts) cout << c << " ";
    cout << endl;

    return 0;
}
