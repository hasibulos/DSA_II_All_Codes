#include <bits/stdc++.h>
using namespace std;

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack01(int wt[], int profit[], int n, int capacity)
{
    // dp[i][j] will store maximum profit using first i items and capacity j
    int dp[n + 1][capacity + 1];

    // Step 1: Build DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // Base case: 0 items or 0 capacity → profit = 0
            else if (wt[i - 1] <= j)
                // Option 1: take the item → profit[i-1] + remaining capacity
                // Option 2: skip the item → previous row value
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            else
                // If item weight is more than capacity → skip the item
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Step 2: Backtracking to find selected items
    int w = capacity;
    vector<int> selected;
    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w]) // means item i was included
        {
            selected.push_back(i); // store item number (1-based)
            w -= wt[i - 1];        // reduce capacity
        }
    }

    // Step 3: Print selected items
    cout << "Selected Items: ";
    for (int i = selected.size() - 1; i >= 0; i--) // reverse order to maintain sequence
        cout << "Item" << selected[i] << " ";
    cout << "\n";

    // Return the maximum profit stored at dp[n][capacity]
    return dp[n][capacity];
}

int main()
{
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int wt[n], profit[n], capacity;

    // Input weights of items
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    // Input profits of items
    cout << "Enter profits of items: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    // Input knapsack capacity
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Function call to calculate maximum profit
    cout << "Maximum Profit (0/1 Knapsack) = "
         << knapsack01(wt, profit, n, capacity) << endl;

    return 0;
}
