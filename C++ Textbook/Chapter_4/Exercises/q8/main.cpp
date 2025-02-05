// Question 8: Calculator
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double a = 0.0;
    double b = 0.0;
    char binOp = ' ';

    cout << "==========" << endl;
    cout << "| **Calculator** (+, -, *, /, %)" << endl;
    
    // Prompt for Input
    do
    {
        cout << "| Enter an expression (e.g., 3.5 + 2.1): ";
        cin >> a >> binOp >> b;

        // Input Validation
        if(cin.fail() || (binOp != '+' && binOp != '-' && binOp != '*' && binOp != '/' && binOp != '%'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two double values and one of the binary operators." << endl;
            cout << "Proper Usage: 'num1' 'binOp' 'num2'" << endl;
        } else if(binOp == '/' && b == 0) {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error: Division by zero is not allowed." << endl;
        } else if(binOp == '%' && b == 0) {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Error: Modulo by zero is not allowed." << endl;
        } else
            break;  // Exit the loop if input is valid
    } while(true);

    // Display Results
    cout << "==========" << endl;
    cout << "| Result: " << a << " " << binOp << " " << b << " = ";
    switch(binOp)
    {
        case '+':
            cout << a + b << endl; 
            break;
        case '-':
            cout << a - b << endl; 
            break;
        case '*':
            cout << a * b << endl; 
            break;
        case '/':
            cout << a / b << endl; 
            break;
        case '%':
            cout << fmod(a, b) << endl; 
            break;
        default:
            // This case is unreachable due to input validation
            cout << "The operation is invalid." << endl;
            break;
    }
    cout << "==========" << endl;

    return 0;
}