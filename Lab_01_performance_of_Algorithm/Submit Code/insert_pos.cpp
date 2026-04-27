#include<iostream>
using namespace std;
int main(){
    int ara[10],n,i,pos,x;
    cout<<"Enter Size of array: ";
    cin>>n;
    cout<<"Enter elements of array: ";
    for(i=0;i<n;i++)
    {
        cin>>ara[i];

    }
    cout<<"Enter a Position or Location: ";
    cin>>pos;
    cout<<"Enter a insert of value: ";
    cin>>x;
    for(int i = n-1; i>=pos-1;i--)
    {
        ara[i+1]=ara[i];

    }
    ara[pos-1]=x;
    n++;
    cout<<"Updated Elements are here: "<<endl;
    for(int i = 0;i<n;i++)
    {
      cout<<ara[i]<<endl;
    }









return 0;
}
