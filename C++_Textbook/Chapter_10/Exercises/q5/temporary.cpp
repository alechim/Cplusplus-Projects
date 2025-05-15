#include <iostream>
#include <iomanip>
#include <cmath>
#include "temporary.h"

using namespace std;

// Class Function Definitions
/**
 * temporary::temporary: Constructor with parameters
 * @param string desc - The name of the shape
 * @param double value1 - The first value to be manipulated
 * @param double value2 - The second value to be manipulated
 */
temporary::temporary(string desc, double value1, double value2)
{
    description = desc;
    first = value1;
    second = value2;
}

/**
 * temporary::print(): Displays the shape, length and width, and calculated results based on description
 */
void temporary::print()
{
    cout << fixed << showpoint << setprecision(2);
    cout << description;
    if(description == "rectangle")
        cout << ": length = " << first << ", width = " << second << ", area = " << manipulate() << endl;
    else if(description == "circle")
        cout << ": radius = " << first << ", area = " << manipulate() << endl;
    else if(description == "sphere")
        cout << ": radius = " << first << ", volume = " << manipulate() << endl;
    else if(description == "cylinder")
        cout << ": radius = " << first << ", height = " << second << ", volume = " << manipulate() << endl;
    else
        cout << ", not able to manipulate." << endl;
}

/**
 * temporary::manipulate: Returns calculations based on description
 * - If "rectangle", return area
 * - If "sphere", return volume with 'first' as the radius
 * - If "cylinder", return volume with 'first' as the radius and 'second' as the height
 * - Otherwise, return -1
 */
double temporary::manipulate()
{
    if(description == "rectangle")
        return first * second;
    else if(description == "circle")
        return M_PI * pow(first, 2.0);
    else if(description == "sphere")
        return 4.0 / 3.0 * M_PI * pow(first, 3.0);
    else if(description == "cylinder")
        return M_PI * pow(first, 2.0) * second;
    else
        return -1;
}

/**
 * +==== Class Setters and Getters ====+
 */
void temporary::set(string desc, double value1, double value2)
{
    description = desc;
    first = value1;
    second = value2;
}
void temporary::get(string& desc, double& value1, double& value2)
{
    desc = description;
    value1 = first;
    value2 = second;
}
void temporary::setDescription(string desc) { description = desc; }
void temporary::setFirst(double value) { first = value; }
void temporary::setSecond(double value) { second = value; }
string temporary::getDescription() const { return description; }
double temporary::getFirst() const { return first; }
double temporary::getSecond() const { return second; }