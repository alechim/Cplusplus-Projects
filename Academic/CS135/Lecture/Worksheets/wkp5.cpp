/* Alec Him, 2001543593, CS 135 1004, Worksheet 5
 * Description: Calculates sin and cos of degrees into radians
 * Input: Double
 * Output: Sin and Cos of Degrees in Radians 
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// Variables
	const double PI = 3.14159;
	double degrees = 0;
	double radians = 0;

	cout << "Enter an angle value, in degrees: ";
	cin >> degrees;

	radians = degrees * PI / 180;

	cout << "sin(" << degrees << ") = " << sin(radians) << endl;
	cout << "cos(" << degrees << ") = " << cos(radians) << endl;

	return 0;
}
