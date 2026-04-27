#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter size of first sorted array: ";
    cin >> n;
    int A[100];
    cout << "Enter first sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter size of second sorted array: ";
    cin >> m;
    int B[100];
    cout << "Enter second sorted array: ";
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int total = n + m;
    int mid = total / 2;
    int i = 0, j = 0, count = 0;
    int prevVal = -1, curVal = -1;
    while (count <= mid)
    {
        prevVal = curVal;
        if (i < n && (j >= m || A[i] <= B[j]))
        {
            curVal = A[i];
            i++;
        }
        else
        {
            curVal = B[j];
            j++;
        }
        count++;
    }
    if (total % 2 == 1)
        cout << "Median = " << curVal << "\n";
    else
        cout << "Median = " << ((prevVal + curVal) / 2.0) << "\n";
    return 0;
}
