#include <iostream>
#include <vector>
using namespace std;

// -----------------------------------------------
// Partition Function (pivot এর চারপাশে items সাজানো)
// -----------------------------------------------
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // শেষ অবস্থানের element কে pivot ধরা হলো
    int i = low - 1;       // ছোট element রাখার জায়গা track করবে

    for (int j = low; j < high; j++) // low থেকে high - 1 পর্যন্ত loop
    {
        if (arr[j] < pivot) // যদি বর্তমান element pivot এর চেয়ে ছোট হয়
        {
            i++;
            swap(arr[i], arr[j]); // ছোট element সামনে তুলে আনা
        }
    }

    swap(arr[i + 1], arr[high]); // pivot কে তার সঠিক sorted position এ বসানো
    return i + 1;                // pivot এর index return
}

// -----------------------------------------------
// Quick Sort Function (Divide and Conquer)
// -----------------------------------------------
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high) // কমপক্ষে ২ টি element থাকলে sort হবে
    {
        int pi = partition(arr, low, high); // pivot থেকে বাম/ডান আলাদা করা

        quickSort(arr, low, pi - 1);  // pivot এর বাম অংশ sort
        quickSort(arr, pi + 1, high); // pivot এর ডান অংশ sort
    }
}

// -----------------------------------------------
// Main Function (User Input + Output)
// -----------------------------------------------
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n; // মোট কয়টি সংখ্যা ইনপুট নিবো?

    vector<int> arr(n); // n সাইজের vector তৈরি করা হলো

    cout << "Enter elements: "; // user অ্যারেতে সংখ্যা দিবে
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1); // full array quicksort

    cout << "Sorted array: "; // sorted array print
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0; // প্রোগ্রাম শেষ
}
