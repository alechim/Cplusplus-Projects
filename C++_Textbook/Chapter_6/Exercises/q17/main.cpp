// Question 17: Function Practice 2
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ***Function Prototypes***
void func1();
void func2(int& a, int& b, double& c);

int main()
{
    // Variables
    int num1 = 0;
    int num2 = 0;
    double num3 = 0.0;
    int choice = 0;

    do
    {
        func1();
        cin >> choice;
        cout << endl;
        if(choice == 1)
        {
            func2(num1, num2, num3);
            cout << num1 << ", " << num2 << ", " << num3 << endl;
        }
    } while(choice != 99);
    
    return 0;
}

// ***Functions***
void func1()
{
    cout << "To run the program, enter 1." << endl;
    cout << "To exit the program, enter 99." << endl;
    cout << "Enter 1 or 99: ";
}

void func2(int& a, int& b, double& c)
{
    do
    {
        cout << "Enter two integer values: ";
        cin >> a >> b;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 2 integer values." << endl;
        } else
            break;
    } while(true);
    
    if(a >= b)
    {
        c = pow(a, b);
        cout << "c = " << a << "^" << b << " = " << c << endl;
    } else if(a < b)
    {
        c = pow(b, a);
        cout << "c = " << b << "^" << a << " = " << c << endl;
    } else if(a != 0 && b == 0)
    {
        c = sqrt(abs(a));
        cout << "c = sqrt(|" << a << "|) = " << c << endl;
    } else if(a == 0 && b != 0)
    {
        c = sqrt(abs(b));
        cout << "c = sqrt(|" << b << "|) = " << c << endl;
    } else
    {
        c = 0;
        cout << "c = 0" << endl;
    }
}