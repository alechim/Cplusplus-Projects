#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double pi = M_PI;
const string planets [8] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
const double planetDiameter [8] = {4879, 12104, 12756, 6792, 142298, 120536, 51118, 49528};
const double planetMass [8] = {0.330*pow(10,24), 4.87*pow(10,24), 5.97*pow(10,24), 
                               0.642*pow(10,24), 1898*pow(10,24), 568*pow(10,24), 
                               86.8*pow(10,24), 102*pow(10,24)};

int main()
{
    // Variables
    double diameter = 0.0, mass = 0.0;
    string planet = "";
    int userInput = 0;
    double radius = 0.0;
	double circumference = 0.0;
	double volume = 0.0;
	double density = 0.0;

    // Display Menu
    cout << "Mercury[1]\nVenus[2]\nEarth[3]\nMars[4]\nJupiter[5]\nSaturn[6]\nUranus[7]\nNeptune[8]" << endl;
    cout << "Welcome to planetary statistics, enter a number corresponding to the planet above to continue: ";

    // Prompt for Input
    cin >> userInput;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Not an integer, try again" << endl;
        cin >> userInput;
    }
    if(userInput < 1 || userInput > 8)
    {
        cout << "Invalid input, try again" << endl;
        cin >> userInput;
    }

    diameter = planetDiameter[userInput - 1];
    mass = planetMass[userInput - 1];
    planet = planets[userInput - 1];

    // Calculations
    radius = diameter / 2;
	circumference = pi * diameter;
	volume = (4/3 * pi * pow(radius, 3.0)) * pow(1000.0, 3.0);
	density = (mass / volume);

    // Display Results
    cout << "Earth Statistics: " << endl;
	cout << "Earth Radius: " << fixed << setprecision(2) << radius << " km" << endl;
	cout << "Earth Circumference: " << fixed << setprecision(2) << circumference << " km" << endl;
	cout << "Earth Volume: " << scientific << volume << " m^3" << endl;
	cout << "Earth Density: " << fixed << setprecision(2) << density << " kg/m^3" << endl;

    return 0;
}