// Example 2-5: Arithmetic Calculator
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int int1 = 0;
    int int2 = 0;
    double dbl1 = 0.0;
    double dbl2 = 0.0;
    int intResult = 0;
    double dblResult = 0.0;
    char binOp = ' ';
    char select = ' ';

    while(true)
    {
        cout << "Integer or Double Arithmetic? [i/d]: ";
        cin >> select;

        if(cin.fail() || (select != 'i' && select != 'd'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input, please enter 'i' or 'd'." << endl;
            continue;
        } else if(select == 'i')
        {
            cout << "Enter the value of the first integer: ";
            cin >> int1;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input, please enter an integer value." << endl; 
                continue;
            }

            cout << "Enter the value of the second integer: ";
            cin >> int2;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input, please enter an integer value." << endl;
                continue;
            }

            cout << "Enter the binary operator (+, -, *, /, %): ";
            cin >> binOp;
            if(cin.fail() || (binOp != '+' && binOp != '-' && binOp != '*' && binOp != '/' && binOp != '%'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input, please enter a binary operator." << endl;
                continue;
            }

            if(int2 == 0 && (binOp == '/' || binOp == '%'))
            {
                cout << "Error: Division by 0 is not allowed." << endl;
                continue;
            }

            switch(binOp)
            {
                case '+': intResult = int1 + int2; break;
                case '-': intResult = int1 - int2; break;
                case '*': intResult = int1 * int2; break;
                case '/': intResult = int1 / int2; break;
                case '%': intResult = int1 % int2; break;
            }

            cout << "The value of " << int1 << " " << binOp << " " << int2 << " is " << intResult << endl; 
            break;
        } else if(select == 'd')
        {
            cout << "Enter the value of the first double: ";
            cin >> dbl1;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input, please enter an double value." << endl; 
                continue;
            }

            cout << "Enter the value of the second double: ";
            cin >> dbl2;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input, please enter a double value." << endl;
                continue;
            }

            cout << "Enter the binary operator (+, -, *, /): ";
            cin >> binOp;
            if(cin.fail() || (binOp != '+' && binOp != '-' && binOp != '*' && binOp != '/'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input, please enter a binary operator." << endl;
                continue;
            }

            if(dbl2 == 0 && binOp == '/')
            {
                cout << "Error: Division by 0 is not allowed." << endl;
                continue;
            }

            switch(binOp)
            {
                case '+': dblResult = dbl1 + dbl2; break;
                case '-': dblResult = dbl1 - dbl2; break;
                case '*': dblResult = dbl1 * dbl2; break;
                case '/': dblResult = dbl1 / dbl2; break;
            }

            cout << "The value of " << dbl1 << " " << binOp << " " << dbl2 << " is " << dblResult << endl; 
            break;
        }
    }

    return 0;
}