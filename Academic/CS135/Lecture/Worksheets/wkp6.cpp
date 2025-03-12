/* Alec Him, 2001543593, CS135 1004, Worksheet 6
 * Description: Calculates the Circumference of a Circle by input of radius
 * Input: Doubles
 * Output: Circumference 
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Variables
	const double PI = 3.14159;
	double radius = 0;
	double circumference = 0;

	cout << "Enter the radius: ";
	cin >> radius;

	circumference = 2 * PI * radius;
	
	cout << fixed << setprecision(2) << "Circumference of a circle with a radius of " << radius << " is " << circumference << endl;

	return 0;
}
