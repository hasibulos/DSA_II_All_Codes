#include <iostream>
using namespace std;

int main()
{
    string employees[] = {"Alice", "Bob", "Charlie", "Diana", "Erwin"};
    int n = 5;
    cout << "Enter employee name to search: ";
    string name;
    cin >> name;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (employees[i] == name)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
        cout << "Not found\n";
    else
        cout << name << " found at index " << index << "\n";
    return 0;
}
