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

// Function to perform Counting Sort
void countingSort(int A[], int n)
{
    int max = getMax(A, n); // use separate getMax()

    // Create count array
    int count[max + 1] = {0};

    // Store count of each element
    for (int i = 0; i < n; i++)
        count[A[i]]++;

    // Modify count array for positions
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[A[i]] - 1] = A[i];
        count[A[i]]--;
    }

    // Copy sorted elements back
    for (int i = 0; i < n; i++)
        A[i] = output[i];
}

// ==================== MAIN FUNCTION ====================
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    countingSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
