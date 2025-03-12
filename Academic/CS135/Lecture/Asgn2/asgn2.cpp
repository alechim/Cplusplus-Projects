/* Alec Him, 2001543593, CS135 1004, Assignment 2
 * Description: Calculates Surface Area and Volume of a Circle after Input of Diameter
 * Input: Doubles
 * Output: States the volume and area 
 */
#include <iostream>     // For console input and output
#include <cmath>        // Gives the program access to sin(), sqrt(), pow(), etc.

using namespace std;

int main()
{
    // Variables
    double d = 0; //Diameter
	double vol = 0; //Volume
	double area = 0; //Surface Area
	const double PI = 3.14159265358;

    // Prompt for Input
    cout << "Enter the diameter of the celestial body (km): ";
	cin >> d;

    // Volume Formula
	vol = 4.0 / 3.0 * PI * pow(d / 2.0, 3.0); 
	cout << "The volume of the celestial body: " << vol << " km" << endl;

    // Surface Area Formula
	area = 4.0 * PI * pow(d / 2.0, 2.0); 
	cout << "The surface area is: " << area << " square km" << endl;

    return 0;
}