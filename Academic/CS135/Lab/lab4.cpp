/* Alec Him, 2001543593, CS135 1009, Lab 4
* Description: Simple Arithmetic Calculator
* Input: First and Second Number and Operand
* Output: Add, Subtract, Multiply or Divide both numbers 
*/
#include <iostream>

using namespace std;

int main()
{
    // Variables
    double num1 = 0.0;
	double num2 = 0.0;
	char operand = ' ';

	cout << "Input First Value: ";
	cin >> num1;
	if(cin.fail())
    {
        cin.clear();
        cin.ignore(40, '\n');
		cout << "Invalid Input." << endl;
		return 1;
	}

	cout << "Input Second Value: ";
	cin >> num2;
	if(cin.fail())
    {
        cin.clear();
        cin.ignore(40, '\n');
		cout << "Invalid Input." << endl;
		return 1;
	}

	cout << "Operation to perform (+,-,/,*): ";
	cin >> operand;

	switch(operand)
    {
		case '+':
			cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
		    break;
		case '-':
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
		    break;
		case '/':
            if (num2 == 0)
                cout << num1 << " / " << num2 << " = Infinity" << endl;
            else 
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
		    break;
		case '*':
			cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
		    break;
		default: 
			cout << "Invalid Input." << endl;
            return 1;
	}

    return 0;
}