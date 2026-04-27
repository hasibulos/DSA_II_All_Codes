#include <iostream>
#include <algorithm>
using namespace std;

// Item struct (প্রতিটি item এর number, weight এবং profit)
struct Item
{
    int item_no, weight, profit;
};

int main()
{
    int n, capacity;

    cout << "Enter no of items: ";
    cin >> n; // মোট item কতটি

    Item ar[n]; // n size array of Item

    cout << "Enter data (item_no weight profit):" << endl;
    for (int i = 0; i < n; i++)
        cin >> ar[i].item_no >> ar[i].weight >> ar[i].profit;
    // প্রতিটি item এর number, weight এবং profit ইনপুট নেওয়া

    cout << "Enter capacity: ";
    cin >> capacity; // ব্যাগের capacity ইনপুট নেওয়া

    int dp[n + 1][capacity + 1]; // DP table তৈরি (item+1)*(capacity+1)

    // --------------------------
    // DP table fill করা
    // --------------------------
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0; // 0 item বা 0 capacity হলে profit 0
            else if (ar[i - 1].weight > j)
                dp[i][j] = dp[i - 1][j]; // item নিতে পারি না → আগের value নাও
            else
                dp[i][j] = max(dp[i - 1][j],
                               ar[i - 1].profit + dp[i - 1][j - ar[i - 1].weight]);
            // item নেওয়া বা না নেওয়া → বেশি profit নাও
        }
    }

    cout << "Maximum Profit: " << dp[n][capacity] << endl; // result print

    // --------------------------
    // Backtracking to find items taken
    // --------------------------
    cout << "Items taken: ";
    int i = n, j = capacity;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {                                     // যদি value change হয়েছে → item i নেওয়া হয়েছে
            cout << ar[i - 1].item_no << " "; // print item number
            j -= ar[i - 1].weight;            // capacity কমাও
        }
        i--; // previous item দেখো
    }
    cout << endl;
}
