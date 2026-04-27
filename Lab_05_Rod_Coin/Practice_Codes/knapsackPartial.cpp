#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
    int item_no;
    float weight,profit,perweight_profit;
};
bool comp(Item &a,Item &b){
    return a.perweight_profit>b.perweight_profit;
}
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
    for(int i=0;i<n;i++){
       ar[i].perweight_profit=ar[i].profit/ar[i].weight;
    }

    sort(ar,ar+n,comp);

    float pro=0;
    for(int i=0;i<n;i++){
            if(capacity>0){
        if(ar[i].weight<capacity){
            pro+=ar[i].profit;
            capacity-=ar[i].weight;
    }
        else{
            pro += ar[i].perweight_profit*capacity;
            capacity-=capacity;
              }
            }
        }

        cout<<"Profit: "<<pro<<endl;
        cout<<capacity<<endl;

    return 0;
}
