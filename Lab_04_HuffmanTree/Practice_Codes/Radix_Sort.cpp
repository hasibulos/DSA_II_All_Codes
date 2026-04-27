#include <iostream>
#include <vector>
using namespace std;

// Counting sort for a specific digit place
void countingSort(vector<int> &arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrence of digits
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (from end to maintain stability)
    for (int i = n - 1; i >= 0; i--)
    {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }
    // ****this part is for descending order sorting****
    // // Count occurrence of digits (same)
    // for (int i = 0; i < n; i++)
    //     count[(arr[i] / exp) % 10]++;

    // // Cumulative count (reverse for descending)
    // for (int i = 8; i >= 0; i--)
    //     count[i] += count[i + 1];

    // // Build output array (from start)
    // for (int i = 0; i < n; i++) {
    //     int index = (arr[i] / exp) % 10;
    //     output[count[index] - 1] = arr[i];
    //     count[index]--;
    // }

    // Copy back to arr
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSortAscending(vector<int> &arr)
{
    // Find max value
    int maxVal = arr[0];
    for (int val : arr)
        if (val > maxVal)
            maxVal = val;

    // Do counting sort for each digit (unit, tens, hundreds...)
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    vector<int> arr;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    radixSortAscending(arr);

    cout << "Sorted Array (Ascending): ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
    return 0;
}
// 🔹 Working Principle

// Step 1: Unit digit (1’s place) দিয়ে sort করো

// Step 2: Tens place দিয়ে sort করো

// Step 3: Hundreds place … (যতক্ষণ পর্যন্ত max value divide > 0)

// Ascending: Counting sort cumulative left→right

// Descending: Counting sort cumulative right→left