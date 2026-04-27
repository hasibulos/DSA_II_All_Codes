#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
    int item_no,weight,profit;
};
int main()
{
    int n,capacity;
    cout<<"Enter no of items:";
    cin>>n;
    Item ar[n];
    cout<<"Enter data,"<<endl;;
    for(int i=0;i<n;i++){
        cin>>ar[i].item_no>>ar[i].weight>>ar[i].profit;
    }
    cout<<endl;
    cout<<"Enter capacity: ";
    cin>>capacity;

    int dp[n+1][capacity+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
            if (i==0 || j==0)
                dp[i][j]=0;
            else if(ar[i-1].weight>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=max(dp[i-1][j],ar[i- 1].profit + dp[i-1][j-ar[i-1].weight]);
        }
    }
    cout<<dp[n][capacity]<<endl;
}

