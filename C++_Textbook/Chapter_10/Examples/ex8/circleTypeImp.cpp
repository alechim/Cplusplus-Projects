#include <iostream>
#include "circleType.h"

using namespace std;

// Class Function Definitions
/**
 * circleType::setRadius: Updates the private instance variable of the class with the passed parameter
 * @param double r - The variable to update radius in the class object
 */
void circleType::setRadius(double r)
{
    radius = ((r >= 0.0) ? r : 0);
}

/**
 * circleType::getRadius: Returns the private instance variable radius of the class
 * @return double - the radius of the circle
 */
double circleType::getRadius()
{
    return radius;
}

/**
 * circleType::area: Calculates the area of the circle using the radius within the class
 * @return double - the area calculated
 */
double circleType::area()
{
    return 3.1416 * radius * radius;
}

/**
 * circleType::circumference: Calculates the circumference of the circle using the radius within the class
 * @return double - the circumference calculated
 */
double circleType::circumference()
{
    return 2 * 3.1416 * radius;
}

/**
 * circleType::circleType: Constructor with parameters
 * @param double r - The variable to intialize radius in the class object
 */
circleType::circleType(double r)
{
    setRadius(r);
}