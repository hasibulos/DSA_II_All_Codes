#include <iostream>
using namespace std;

int stepCount = 0;

int sumOfDigits(int n)
{
    stepCount++;

    // Base Case
    if (n == 0)
    {
        return 0;
    }
    // Recursive Case
    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = sumOfDigits(num);

    cout << "Sum of digits of " << num << " = " << result << endl;
    cout << "Total Steps  = " << stepCount << endl;

    return 0;
}
