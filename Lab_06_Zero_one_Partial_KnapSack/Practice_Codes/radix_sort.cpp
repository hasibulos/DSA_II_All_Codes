#include <iostream>
using namespace std;

// Function to get maximum value in array
int getMax(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp (1 = unit place, 10 = tens place, etc.)
void countSort(int A[], int n, int exp)
{
    int output[n]; // output array
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(A[i] / exp) % 10]++;

    // Change count[i] so that it contains actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(A[i] / exp) % 10] - 1] = A[i];
        count[(A[i] / exp) % 10]--;
    }

    // Copy to original array
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

// Main Radix Sort function
void radixSort(int A[], int n)
{
    int m = getMax(A, n); // find the maximum number

    // Apply counting sort for every digit
    for (int pos = 1; m / pos > 0; pos *= 10)
        countSort(A, n, pos);
}

// Driver Code
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    radixSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
