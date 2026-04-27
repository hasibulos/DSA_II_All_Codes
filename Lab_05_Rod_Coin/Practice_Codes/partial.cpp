#include <bits/stdc++.h>
using namespace std;
struct Node
{
    float weight, profit, perweightProfit;
};
bool compareByPerWeightProfit(const Node &a, const Node &b)
{
    return a.perweightProfit > b.perweightProfit;
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
    for (int i = 0; i < n; i++)
    {
        ara[i].perweightProfit = ara[i].profit / ara[i].weight;
    }
    sort(ara, ara + n, compareByPerWeightProfit);
    float current_weight = 0, current_profit = 0;
    int items_picked[n];
    for (int i = 0; i < n; i++)
    {
        if (current_weight >= capacity)
        {
            break;
        }
        if (ara[i].weight <= capacity - current_weight)
        {
            current_weight += ara[i].weight;
            current_profit += ara[i].profit;
        }
        else
        {
            float weightLeft = capacity - current_weight;
            current_weight += weightLeft;
            current_profit += (ara[i].perweightProfit * weightLeft);
            break;
        }
    }
    cout << "\nWeight Taken: " << current_weight;
    cout << "\nProfit Taken: " << current_profit;
}