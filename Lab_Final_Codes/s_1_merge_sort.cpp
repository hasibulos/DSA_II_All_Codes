#include <iostream>  // ইনপুট-আউটপুট ব্যবহারের জন্য প্রয়োজন
using namespace std; // std:: না লিখে সরাসরি cout, cin ব্যবহার করা যাবে

// ---------------------------------------------------------
// Function Declaration (Prototype)
// আগে বলে দিচ্ছি যে dividearray() এবং mergearray() নামে দুইটা
// ফাংশন আছে — পরে আমি ওগুলো লিখব।
// ---------------------------------------------------------
void dividearray(int arr[], int left, int right);
void mergearray(int arr[], int left, int mid, int right);

// ---------------------------------------------------------
// Divide Function (অ্যারেকে দুই ভাগে ভাগ করে)
// ---------------------------------------------------------
void dividearray(int arr[], int left, int right)
{
    if (left >= right) // left == right হলে একটাই element থাকে
        return;        // তখন আর sort করার দরকার নেই

    int mid = left + (right - left) / 2; // অ্যারের মাঝের index বের করা

    dividearray(arr, left, mid);      // বাম অংশকে আবার ভাগ করা
    dividearray(arr, mid + 1, right); // ডান অংশকে আবার ভাগ করা

    mergearray(arr, left, mid, right); // দুই ভাগ merge করা (sorting এখানে হয়)
}

// ---------------------------------------------------------
// Merge Function (দুই অংশকে সাজানোভাবে একত্র করে)
// ---------------------------------------------------------
void mergearray(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // বাম অংশে কয়টি element আছে
    int n2 = right - mid;    // ডান অংশে কয়টি element আছে

    int arr1[n1], arr2[n2]; // দুইটা temporary array তৈরি

    // বাম দিকের অংশ arr1[] এ কপি করা
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[left + i];

    // ডান দিকের অংশ arr2[] এ কপি করা
    for (int j = 0; j < n2; j++)
        arr2[j] = arr[mid + 1 + j];

    int i = 0, j = 0; // arr1 ও arr2 এর current index
    int k = left;     // মূল array-তে merge শুরু হবে left থেকে

    // দুই অংশ তুলনা করে ছোটটাকে main array তে রাখা
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j]) // যদি arr1 এর element ছোট হয়
        {
            arr[k] = arr1[i]; // arr1 এর element main array তে রাখি
            i++;              // arr1 এর পরের element এ যাই
        }
        else // arr2 এর element ছোট হলে
        {
            arr[k] = arr2[j]; // arr2 এর element main array তে রাখি
            j++;              // arr2 এর পরের element এ যাই
        }
        k++; // main array এর পরের জায়গায় যাই
    }

    // যদি arr1 এ element বাকি থাকে — সেগুলো main array তে কপি
    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // যদি arr2 এ element বাকি থাকে — সেগুলো main array তে কপি
    while (j < n2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

// ---------------------------------------------------------
// Main Function (প্রোগ্রামের শুরু)
// ---------------------------------------------------------
int main()
{
    int n;
    cout << "Enter number of elements: "; // কয়টি সংখ্যা নিবো?
    cin >> n;

    int arr[n]; // n সংখ্যার array তৈরি

    cout << "Enter elements: "; // সব element ইনপুট নিবো
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // ইউজার অ্যারে তে মান দিচ্ছে
    }

    dividearray(arr, 0, n - 1); // full array কে divide → merge → sort করা

    cout << "Sorted Array: "; // সাজানো array দেখানো
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // প্রতিটা element print
    }
    cout << endl;

    return 0; // প্রোগ্রাম শেষ
}
