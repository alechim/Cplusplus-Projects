/* CS135 1009 Lab
 * Alec Him 
 */
#include <iostream>     // cout, cin
#include <cmath>        // pow(), sqrt()

using namespace std;

int main()
{
    // Variables
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double x1 = 0.0;
    double x2 = 0.0;
	double disc;    //discriminant

    cout << "Enter value for a: ";
	cin >> a;

	cout << "Enter value for b: ";
	cin >> b;

	cout << "Enter value for c: ";
	cin >> c;

	cout << "The quadratic equation is: " << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

    disc = pow(b, 2.0) - (4 * a * c);
    
    x1 = (-b + sqrt(disc)) / (2 * a);
	cout << "x1 = " << x1 << endl;
	
    x2 = (-b - sqrt(disc)) / (2 * a);
	cout << "x2 = " << x2 << endl;

    return 0;
}