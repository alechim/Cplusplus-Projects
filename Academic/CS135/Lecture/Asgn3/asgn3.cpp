/* Alec Him, 2001543593, CS135 1004, Assignment 3
 * Description: Calculates the Size of a Super Laser
 * Input: Doubles
 * Output: Height, Lateral Surface, Area, Volume, Focal Point, Gain 
 */
#include <iostream>     // For console input and output
#include <cmath>        // Gives the program access to sin(), sqrt(), pow(), etc.

using namespace std;

int main()
{
    // Variables
    const double PI = 3.141592653589;
	double height = 0.0;
	double diameter = 0.0;
	double radius = 0.0;
	double slantHeight = 0.0;
	double lateralSurface = 0.0;
	double surfaceArea = 0.0;
	double volume = 0.0;
	double focalPoint = 0.0;
	double k = 0.0;
	double waveLength = 0.0;
	double gain = 0.0;

    cout << "\n*******************************************\n";
	cout << "** Rebel Alliance Computational Division **\n";
	cout << "*******************************************\n\n";

    // Prompt for Input - 1
    cout << "Enter the diameter of the super laser lens(km): ";
	cin >> diameter;

	cout << "Enter the height of the lens(km): ";
	cin >> height;

    cout << "\n--------------------------------------------\n";
	cout << "Specifications for Super Laser" << endl;
	cout << "Height: " << height << " km" << endl;
	cout << "Diameter: " << diameter << " km" << endl;
	cout << "--------------------------------------------\n";

    // Calculations - 1
    radius = diameter / 2.0;
	slantHeight = sqrt(pow(height, 2.0) + pow(radius, 2.0));
	lateralSurface = radius * slantHeight * PI;
	surfaceArea = radius * PI * (radius + slantHeight);
	volume = 1.0 / 3.0 * pow(radius, 2.0) * PI * height;
	focalPoint = (pow((2 * radius), 2.0)) / (16 * height);

    // Display Results - 1
    cout << "Slant Height: " << slantHeight << " km" << endl;
	cout << "Lateral Surface: " << lateralSurface << " km" << endl;
	cout << "Area: " << surfaceArea << " km squared" << endl;
	cout << "Volume: " << volume << " km cubed" << endl;
	cout << "Focal Point: " << focalPoint << " km" << endl << endl;

    // Prompt for Input - 2
    cout << "Enter the efficiency of the lens/antenna: ";
	cin >> k;

	cout << "Enter the wave length (meters): ";
	cin >> waveLength;

    // Calculations - 2
    gain = 10 * log10(k * pow((PI * diameter / waveLength), 2.0));

    // Display Results - 2
    cout << "The Super Laser lens gain is: " << gain << " dB" << endl << endl;

	cout << "<<<<<<<<<<< - >>>>>>>>>>>" << endl;
	cout << "May the Force be with you!" << endl;
	cout << "<<<<<<<<<<< - >>>>>>>>>>>" << endl;

    return 0;
}