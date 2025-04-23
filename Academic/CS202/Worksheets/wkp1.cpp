#include <iostream>

using namespace std;

// Function Prototype
int powNumber(int, int);

int main()
{
    int num = 0, exp = 0, total = 0;

    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the exponent: ";
    cin >> exp;

    total = powNumber(num, exp);

    cout << num << "^" << exp << " = " << total << endl;

    return 0;
}

// Function Definition
int powNumber(int num, int exp)
{
    int total = num;
    if(exp == 1)
        return total;
    else
    {
        for(int i = 1; i < exp; i++)
            total *= num;
    }

    return total;
}