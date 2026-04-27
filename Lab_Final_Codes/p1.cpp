//#include<bits/stdc++.h>
//using namespace std;
//
//// Function declarations
//void divarr(int arr[], int l, int r);
//void mergearr(int arr[], int l, int m, int r);
//
//// Divide function: array কে ভাগ করে
//void divarr(int arr[], int l, int r){
//    if(l >= r){  // যদি left >= right হয়, আর ভাগ করার দরকার নেই
//        return;
//    }
//    int m = l + (r - l)/2;  // mid বের করা
//    divarr(arr, l, m);      // বাম ভাগকে আবার divide করা
//    divarr(arr, m+1, r);    // ডান ভাগকে divide করা
//    mergearr(arr, l, m, r); // দুই ভাগ merge করা
//}
//
//// Merge function: দুই ভাগকে sorted করে merge করা
//void mergearr(int arr[], int l, int m, int r){
//    int n1 = m - l + 1;  // বাম ভাগের size
//    int n2 = r - m;      // ডান ভাগের size
//    int arr1[n1], arr2[n2]; // temporary arrays
//
//    // বাম অংশ arr1 এ কপি
//    for(int i = 0; i < n1; i++){
//        arr1[i] = arr[l + i];
//    }
//
//    // ডান অংশ arr2 এ কপি
//    for(int j = 0; j < n2; j++){
//        arr2[j] = arr[m + 1 + j];
//    }
//
//    int i = 0, j = 0; // arr1 ও arr2 এর index
//    int k = l;        // মূল array তে index
//
//    // দুটি array compare করে main array তে লেখা
//    while(i < n1 && j < n2){
//        if(arr1[i] <= arr2[j]){
//            arr[k] = arr1[i];
//            i++;
//        } else {
//            arr[k] = arr2[j];
//            j++;
//        }
//        k++;
//    }
//
//    // যদি arr1 এ element বাকি থাকে
//    while(i < n1){
//        arr[k] = arr1[i];
//        i++;
//        k++;
//    }
//
//    // যদি arr2 এ element বাকি থাকে
//    while(j < n2){
//        arr[k] = arr2[j];
//        j++;
//        k++;
//    }
//}
//
//// Main function
//int main(){
//    int n;
//    cout << "Enter n : ";
//    cin >> n;
//    int arr[n];
//
//    cout << "Enter Elements: ";
//    for(int i = 0; i < n; i++){
//        cin >> arr[i];
//    }
//
//    divarr(arr, 0, n-1); // array sort করা
//
//    cout << "Sorted array: ";
//    for(int i = 0; i < n; i++){
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//    return 0;
//}
#include<stdio.h>
int main (){
    char a[100];

printf("input your wife name: ");
//scanf("%s",&a);
fgets(a,sizeof(a),stdin);

printf("this is my sexy wife : %s ",a);

return 0;
}
