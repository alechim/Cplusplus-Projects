#include <iostream>
#include "circleType.h"

using namespace std;

// Class Function Definitions
/**
 * circleType::setRadius
 * @param double r - 
 */
void circleType::setRadius(double r)
{
    radius = ((r >= 0.0) ? r : 0);
}

/**
 * circleType::getRadius: 
 * @return double - 
 */
double circleType::getRadius()
{
    return radius;
}

/**
 * circleType::area: 
 * @return double - 
 */
double circleType::area()
{
    return 3.1416 * radius * radius;
}

/**
 * circleType::circumference: 
 * @return double - 
 */
double circleType::circumference()
{
    return 2 * 3.1416 * radius;
}

/**
 * circleType::circleType: 
 * @param double r - 
 */
circleType::circleType(double r)
{
    setRadius(r);
}