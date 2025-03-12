/* Alec Him, 2001543593, CS135 1009, Lab 2
 * Description: Converts Fahrenheit into other measurements of energy
 * Input: Double
 * Output: Different conversions of energy 
 */
#include <iostream>

using namespace std;

int main()
{
    // Variables
    double fahrenheit = 0.0;
	double celsius = 0;
	double kelvin = 0.0;
	double rankine = 0.0;
	double romer = 0.0;

    cout << "Please enter the temperature in Fahrenheit: ";
	cin >> fahrenheit;

	celsius = (fahrenheit - 32) * 5 / 9;
	cout << fahrenheit << "Fahrenheit = " << celsius << " celsius." << endl;

	kelvin = celsius + 273.15;
	cout << fahrenheit << "Fahrenheit = " << kelvin << " kelvin." << endl;

	rankine = (celsius + 273.15) * 9 / 5;
	cout << fahrenheit << "Fahrenheit = " << rankine << " rankine." << endl;

	romer = celsius * 21 / 40 + 7.5;
	cout << fahrenheit << "Fahrenheit = " << romer << " romer." << endl;

    return 0;
}