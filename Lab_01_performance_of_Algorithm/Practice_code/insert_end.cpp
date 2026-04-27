#include<iostream>
using namespace std;
int main()
{
    int arr[10],n,i,x;
    cout<<"Enter Size of Array: ";
    cin>>n;
    cout<<"Enter Elements of Array: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter a value of insert at End: ";
    cin>>x;
    arr[i]=x;
    n++;
    cout<<"Updated Array Elements here: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;

    }









    return 0;
}
