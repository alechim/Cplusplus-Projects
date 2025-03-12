/* Alec Him, 2001543593, CS135 1004, Worksheet 7
 * Description: Determines which number and string of the two inputted is a higher value
 * Input: Doubles and Strings
 * Output: Largest of the Double and String 
 */
#include <iostream>

using namespace std;

int main()
{
	// Variables
	double frstDbl = 0;
	double scndDbl = 0;
	string frstStr = "";
	string scndStr = "";

	// Prompt Input - 1
	cout << "Enter two numbers (double): ";
	cin >> frstDbl >> scndDbl;

	cout << "You entered " << frstDbl << " and " << scndDbl << endl;

	if(frstDbl > scndDbl)
		cout << "The largest is " << frstDbl << endl;
	else if(frstDbl < scndDbl)
		cout << "The largest is " << scndDbl << endl;

	// Prompt Input - 2
	cout << "Enter two strings: ";
	cin >> frstStr >> scndStr;

	cout << "You entered " << "\"" << frstStr << "\"" << " and " << "\"" << scndStr << "\"" << endl;

	if(frstStr > scndStr)
		cout << "The largest is " << "\"" << frstStr << "\"" << endl;
	else if(frstStr < scndStr)
		cout << "The largest is " << "\"" << scndStr << "\"" << endl;

	return 0;
}
