#include<iostream>
using namespace std;
int main()
{
    int arr[10],n,x,i;
    cout<<"Enter Size of Array: ";
    cin>>n;
    cout<<"Enter Elements of Array: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<"Enter a Value of Insert at First: ";
    cin>>x;
    for(i = n;i>=0;i--)
    {
        arr[i]=arr[i-1];

    }
    arr[0]=x;
    n++;
    cout<<"Updated Elements are Here: "<<endl;
    for(i = 0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }







    return 0;
}
