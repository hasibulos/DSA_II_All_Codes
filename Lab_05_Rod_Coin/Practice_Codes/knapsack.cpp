#include <bits/stdc++.h>
using namespace std;
struct Node
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
    Node ara[n];
    cout << "Enter items weight and Profit: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i].weight >> ara[i].profit;
    }
    int gridCell[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                gridCell[i][w] = 0;
            }
            else if (ara[i - 1].weight <= w)
            {

                gridCell[i][w] = findMax(ara[i - 1].profit + gridCell[i - 1][w -
                                                                             ara[i - 1].weight],
                                         gridCell[i - 1][w]);
            }

            else
            {
                gridCell[i][w] = gridCell[i - 1][w];
            }
        }
    }
    cout << "\nProfit Taken: " << gridCell[n][capacity];
}
