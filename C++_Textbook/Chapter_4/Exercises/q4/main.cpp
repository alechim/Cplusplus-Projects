// Question 4: Shape Calculations
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

// Global Constants 
const double PI = 3.1416;

int main()
{
    // Variables
    string shape = "";

    // Prompt for Input
    cout << "Enter the shape type: (rectangle, circle, cylinder) ";
    cin >> shape;
    cout << endl;

    cout << fixed << showpoint << setprecision(2);
    if(shape == "rectangle")
    {
        // Variables
        double length = 0.0;
        double width = 0.0;
        
        // Prompt for Input
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << endl;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
        cout << endl;

        // Display Results
        cout << "Perimeter of the rectangle = " << 2 * (length + width) << endl;
        cout << "Area of the rectangle = " << length * width << endl;
    } else if(shape == "circle")
    {
        // Variables
        double radius = 0.0;
        
        // Prompt for Input
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        cout << endl;

        // Display Results
        cout << "Circumference of the circle: " << 2 * PI * radius << endl;
        cout << "Area of the circle: " << PI * pow(radius, 2.0) << endl;
    } else if(shape == "cylinder")
    {
        // Variables
        double radius = 0.0;
        double height = 0.0;

        // Prompt for Input
        cout << "Enter the height of the cylinder: ";
        cin >> height;
        cout << endl;
        cout << "Enter the radius of the base of the cylinder: ";
        cin >> radius;
        cout << endl;

        // Display Results
        cout << "Surface area of the cylinder: " << 2 * PI * radius * height + 2 * PI * pow(radius, 2.0) << endl;
        cout << "Volume of the cylinder = " << PI * pow(radius, 2.0) * height << endl;
    } else
        cout << "The program does not handle " << shape << endl;

    return 0;
}