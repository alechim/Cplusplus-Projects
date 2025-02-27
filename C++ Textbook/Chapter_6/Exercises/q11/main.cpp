// Question 11: Circle Calculation based on two points
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ***Globals***
const double PI = 3.1416;

// ***Function Prototypes***
double distance(int x1, int y1, int x2, int y2);
double radius(int x1, int y1, int x2, int y2);
double circumference(double radius);
double area(double radius);

int main()
{
    // Variables
    double r = 0.0;
    int centerX = 0;
    int centerY = 0;
    int pointX = 0;
    int pointY = 0;

    // Prompt for Input
    do
    {
        cout << "Enter the center point of the circle: ";
        cin >> centerX >> centerY;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two integer values (x, y)." << endl;
            continue;
        }

        cout << "Enter a point on the circle: ";
        cin >> pointX >> pointY;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two integer values (x, y)." << endl;
        } else
            break;
    } while(true);
    
    // Display Results
    r = radius(centerX, centerY, pointX, pointY);
    cout << "----------\n";
    cout << "The radius of the circle is " << r << ".\n";
    cout << "The diameter of the circle is " << 2.0 * r << ".\n";
    cout << "The circumference of the circle is " << circumference(r) << ".\n";
    cout << "The area of the circle is " << area(r) << ".\n";
    cout << "----------\n";

    return 0;
}

// ***Functions***
double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2.0) + (pow((y2 - y1), 2.0)));
}

double radius(int x1, int y1, int x2, int y2)
{
    return distance(x1, y1, x2, y2);
}

double circumference(double radius)
{
    return 2 * PI * radius;
}

double area(double radius)
{
    return PI * pow(radius, 2.0);
}