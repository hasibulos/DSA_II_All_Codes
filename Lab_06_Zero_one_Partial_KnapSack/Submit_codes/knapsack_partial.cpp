#include <bits/stdc++.h>
using namespace std;

// Structure to store information of each item
struct Item
{
    int index;    // item number (1-based)
    int weight;   // weight of the item
    int profit;   // profit of the item
    double ratio; // profit-to-weight ratio
};

// Comparator function for sorting items by ratio in descending order
bool cmp(Item a, Item b)
{
    return a.ratio > b.ratio;
}

// Function to solve Fractional Knapsack problem
double fractionalKnapsack(int wt[], int profit[], int n, int capacity)
{
    Item items[n];

    // Step 1: Store item details in the structure
    for (int i = 0; i < n; i++)
    {
        items[i].index = i + 1; // item number (1-based)
        items[i].weight = wt[i];
        items[i].profit = profit[i];
        items[i].ratio = (double)profit[i] / wt[i]; // calculate profit/weight ratio
    }

    // Step 2: Sort items in descending order of ratio
    sort(items, items + n, cmp);

    double totalProfit = 0.0;
    vector<pair<int, double>> taken; // stores item number and fraction taken

    // Step 3: Pick items until knapsack is full
    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            // Take the whole item
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
            taken.push_back({items[i].index, 1.0}); // 100% of item taken
        }
        else
        {
            // Take fraction of the item
            double fraction = (double)capacity / items[i].weight;
            totalProfit += items[i].profit * fraction;
            taken.push_back({items[i].index, fraction}); // fraction of item taken
            capacity = 0;                                // knapsack is now full
            break;
        }
    }

    // Step 4: Display selected items with fractions
    cout << "Selected Items: ";
    for (auto p : taken)
    {
        cout << "Item" << p.first << "(" << p.second * 100 << "%) ";
    }
    cout << "\n";

    return totalProfit; // return the maximum profit
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

    // Input capacity of knapsack
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Function call to calculate maximum profit
    cout << "Maximum Profit (Fractional Knapsack) = "
         << fractionalKnapsack(wt, profit, n, capacity) << endl;

    return 0;
}
