#include<iostream>
#include<algorithm>
using namespace std;

// Item struct: প্রতিটি item এর number, weight, profit এবং profit/weight ratio
struct Item {
    int item_no;
    double weight, profit, ratio;
};

// Compare function for sorting items by profit/weight ratio decreasingly
bool cmp(Item a, Item b){
    return a.ratio > b.ratio; // বেশি ratio আগে
}

int main(){
    int n;
    double capacity;

    cout << "Enter number of items: ";
    cin >> n; // মোট items

    Item ar[n];
    cout << "Enter data (item_no weight profit): " << endl;
    for(int i=0; i<n; i++){
        cin >> ar[i].item_no >> ar[i].weight >> ar[i].profit;
        ar[i].ratio = ar[i].profit / ar[i].weight; // profit/weight ratio
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity; // ব্যাগের capacity

    // --------------------------
    // Step 1: Sort items by ratio
    // --------------------------
    sort(ar, ar+n, cmp);

    double totalProfit = 0;
    cout << "Items taken (fractional):" << endl;

    // --------------------------
    // Step 2: Take items greedily
    // --------------------------
    for(int i=0; i<n; i++){
        if(capacity == 0) break; // ব্যাগ ফাঁকা হলে stop

        if(ar[i].weight <= capacity){
            // পুরো item নেওয়া যায়
            cout << "Item " << ar[i].item_no << " (full)" << endl;
            totalProfit += ar[i].profit;
            capacity -= ar[i].weight;
        } else {
            // fractionally নেওয়া
            double fraction = capacity / ar[i].weight;
            cout << "Item " << ar[i].item_no << " (" << fraction*100 << "%)" << endl;
            totalProfit += ar[i].profit * fraction;
            capacity = 0; // ব্যাগ full
        }
    }

    cout << "Maximum Profit: " << totalProfit << endl;
}
