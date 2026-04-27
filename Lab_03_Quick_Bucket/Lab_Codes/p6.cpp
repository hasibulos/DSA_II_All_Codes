#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of scores: ";
    cin >> n;
    int scores[100];
    cout << "Enter scores: ";
    for (int i = 0; i < n; i++)
        cin >> scores[i];
    int bestIdx = 0;
    for (int i = 1; i < n; i++)
    {
        if (scores[i] > scores[bestIdx])
            bestIdx = i;
    }
    cout << "Highest score = " << scores[bestIdx] << " at index " << bestIdx << "\n";
    return 0;
}
