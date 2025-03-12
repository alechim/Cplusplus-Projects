#include <iostream>

using namespace std;

void writeName(int, string);

int main()
{
    // Variables
    int count = 0;
    string name = "";

    cout << "Enter a number and a name: ";
    cin >> count >> name;

    writeName(count, name);

    return 0;
}

void writeName(int count, string name)
{
    while (count > 0)
    {
        cout << name << " ";
        count--;
    }
    cout << endl;
}
