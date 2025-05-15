// Question 1: Enumeration Triangle Shape
#include <iostream>

using namespace std;

// Enumerators
/**
 * - Scalene Triangle - Three sides are all different
 * - Isosceles Triangle - Two sides are the same
 * - Equilateral Triangle - All three sides are the same
 * - No Triangle iff the one of the following are not true
 *   > a + b > c
 *   > a + c > b
 *   > b + c > a
 */
enum triangleType {scalene, isosceles, equilateral, noTriangle};

// Function Prototype
triangleType triangleShape(double, double, double);
void promptInput(double&, string);

int main()
{
    // Variables
    double a = 0.0, b = 0.0, c = 0.0;
    
    // Prompt for User Input
    promptInput(a, "Please enter the length of the first side of the shape: ");
    promptInput(b, "Please enter the length of the second side of the shape: ");
    promptInput(c, "Please enter the length of the third side of the shape: ");
    
    // Find the type of shape
    triangleType triangle = triangleShape(a, b, c);

    // Display Results
    cout << "+----------+" << endl;
    cout << "The shape made from the three sides is ";
    switch(triangle)
    {
        case scalene:
            cout << "a scalene triangle.";
            break;
        case isosceles:
            cout << "an isosceles triangle.";
            break;
        case equilateral:
            cout << "an equilateral triangle.";
            break;
        case noTriangle:
            cout << "not a triangle.";
            break;
    }
    cout << "\n+----------+" << endl;

    return 0;
}

// Function Definitions
/**
 * triangleShape: Determines the type of triangle based on the given side lengths
 * @param double a - The length of the first side of the triangle
 * @param double b - The length of the second side of the triangle
 * @param double c - The length of the third side of the triangle
 * @return triangleType - The type of triangle (scalene, isosceles, equilateral, or noTriangle)
 */
triangleType triangleShape(double a, double b, double c)
{
    if((a + b) <= c || (a + c) <= b || (b + c) <= a)
        return noTriangle;
    else if(a == b && a == c)
        return equilateral;
    else if(a == b || a == c || b == c)
        return isosceles;
    else if(a != b && b != c && a != c)
        return scalene;
    
    return noTriangle;
}

/**
 * promptInput: Prompts the user for input and validates it's a positive non-zero value
 * @param double& value - Reference to the variable where the validated input will be stored
 * @param string prompt - The message to display when prompting the user for input
 */
void promptInput(double& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        
        // Validate Input
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}