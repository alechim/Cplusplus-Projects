// Question 8: Menu Driven Shape Calculations
#include <iostream>
#include <iomanip>

// ***Globals***
const double PI = 3.1419;

// ***Function Prototypes***
double rectangle(double l, double w);
double circle(double r);
double cylinder(double bR, double h);

using namespace std;

int main()
{
    // Variables
    int choice = 0;
    double length = 0.0;
    double width = 0.0;
    double radius = 0.0;
    double height = 0.0;

    do
    {
        cout << fixed << showpoint << setprecision(2) << endl;
        cout << "This program can calculate the area of a rectangle, the area of a circle, or volume of a cylinder." << endl;
        cout << "| 1: To find the area of rectangle." << endl;
        cout << "| 2: To find the area of a circle." << endl;
        cout << "| 3. To find the volume of a cylinder." << endl;
        cout << "| -1: To terminate the program." << endl;
        cout << "To run the program, enter choice: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                // Prompt for Input
                cout << "Enter the length and width of the rectangle: ";
                cin >> length >> width;
                cout << endl;

                // Calculate and Display Results
                cout << "Area = " << rectangle(length, width) << endl;
                break;
            case 2:
                // Prompt for Input
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                cout << endl;

                // Calculate and Display Results
                cout << "Area = " << circle(radius) << endl;
                break;
            case 3:
                // Prompt for Input
                cout << "Enter the radius of the base and the height of the cylinder: ";
                cin >> radius >> height;
                cout << endl;

                // Calculate and Display Results
                cout << "Volume = " << cylinder(radius, height) << endl;
                break;
            case -1:
                break;
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    } while (choice != -1);
    

    return 0;
}

// ***Functions***
double rectangle(double l, double w)
{
    return l * w;
}

double circle(double r)
{
    return PI * r * r;
}

double cylinder(double bR, double h)
{
    return PI * bR * bR * h;
}