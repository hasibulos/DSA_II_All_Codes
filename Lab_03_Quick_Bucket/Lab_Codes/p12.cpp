#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    string name[100];
    int mark[100];
    cout << "Enter names:\n";
    for (int i = 0; i < n; i++)
        cin >> name[i];
    cout << "Enter marks:\n";
    for (int i = 0; i < n; i++)
        cin >> mark[i];
    for (int pass = 0; pass < n - 1; pass++)
    {
        for (int i = 0; i < n - 1 - pass; i++)
        {
            int needSwap = 0;
            if (mark[i] < mark[i + 1])
                needSwap = 1;
            else if (mark[i] == mark[i + 1] && name[i] > name[i + 1])
                needSwap = 1;
            if (needSwap)
            {
                int tmpM = mark[i];
                mark[i] = mark[i + 1];
                mark[i + 1] = tmpM;
                string tmpN = name[i];
                name[i] = name[i + 1];
                name[i + 1] = tmpN;
            }
        }
    }
    cout << "Sorted list:\n";
    for (int i = 0; i < n; i++)
        cout << name[i] << " " << mark[i] << "\n";
    return 0;
}
