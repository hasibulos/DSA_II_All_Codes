#include <bits/stdc++.h>
using namespace std;
struct hasib
{
    int weight, profit;
};
int findMax(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    int n, capacity;
    cout << "Enter Knapsack Capacity: ";
    cin >> capacity;
    cout << "Enter Number of Items: ";
    cin >> n;
    hasib ara[n];
    cout << "Enter items weight and Profit: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i].weight >> ara[i].profit;
    }
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (ara[i - 1].weight <= w)
            {

                dp[i][w] = findMax(ara[i - 1].profit + dp[i - 1][w -
                                   ara[i - 1].weight],
                                   dp[i - 1][w]);
            }

            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "\nProfit Taken: " << dp[n][capacity];
}
