#include <iostream>
#include "lineType.h"

using namespace std;

/**
 * lineType::determineSlope: Calculates the slope of the class object using the instance variables, a & b
 * @return double - The slope of the equation
 */
double lineType::determineSlope()
{
    // ax + by = c
    // by = c - ax
    // y = (-ax / b) + (c / b)
    return -a / b;
}

/**
 * lineType::determineEqualLines: Checks if the values of both lines are equal or if the values of one line are a ratio of the other
 * @param lineType& line - The line to be compared to
 * @return bool - True, if lines are equal. Otherwise, false
 */
bool lineType::determineEqualLines(lineType& line)
{
    if(a == line.a && b == line.b && c == line.c)
        return true;

    // Check if one variable in the line is 0 but not the other
    if((a == 0.0 && line.a != 0.0) || (a != 0.0 && line.a == 0.0) || 
       (b == 0.0 && line.b != 0.0) || (b != 0.0 && line.b == 0.0) || 
       (c == 0.0 && line.c != 0.0) || (c != 0.0 && line.c == 0.0))
        return false;

    // Calculate each ratio for variables
    double k1 = ((abs(line.a) > abs(a)) ? line.a / a : a / line.a);
    double k2 = ((abs(line.b) > abs(b)) ? line.b / b : b / line.b);
    double k3 = ((abs(line.c) > abs(c)) ? line.c / c : c / line.c);

    if(abs(k1 - k2) < 0.0001 && abs(k2 - k3) < 0.0001)
        return true;

    return false;
}

/**
 * lineType::determineParallelLines: If both lines have the same slopes but different y-intercepts, the lines are parallel
 * @param lineType& line - The line to be compared to
 * @return bool - True, if lines are parallel. Otherwise, false
 */
bool lineType::determineParallelLines(lineType& line)
{
    if((a == 0 && line.a == 0 && abs(b * line.c - line.b * c) > 0.0001) || (b == 0 && line.b == 0 && abs(a * line.c - line.a * c) > 0.0001))
        return true;
    if(abs(determineSlope() - line.determineSlope()) < 0.0001 && c != line.c)
        return true;
    return false;
}

/**
 * lineType::determinePerpendicularLines: If one slope is the product of the slopes is -1 or one is 
 *                                        horizontal and the other vertical, the lines are perpendicular
 * @param lineType& line - The line to be compared to
 * @return bool - True, if lines are perpendicular. Otherwise, false
 */
bool lineType::determinePerpendicularLines(lineType& line)
{
    if(abs(determineSlope() * line.determineSlope() + 1) < 0.001 || 
      (a == 0.0 && line.a != 0.0 && line.b == 0.0 && b != 0.0) || 
      (b == 0.0 && line.b != 0.0 && line.a == 0.0 && a != 0.0))
        return true;
    return false;
}

/**
 * lineType::pointOfIntersection: Finds the point of intersection between both lines
 * @param lineType& line - The line to be compared to
 */
void lineType::pointOfIntersection(lineType& line)
{
    // ax + by = c
    // by = c - ax
    // y = (c - ax) / b

    // (c - ax) / b = (c_1 - a_1x) / b_1
    // b_1(c - ax) = b(c_1 - a_1x)
    // ax * b_1 + c * b_1 = a_1x * b + c_1 * b
    // ax * b_1 - a_1x * b = c_1 * b - c * b_1
    // x = c_1 * b - c * b_1 / a * b_1 - a_1 * b

    double x = 0.0, y = 0.0;

    // Special case: first line is vertical (a != 0, b = 0)
    if(abs(b) < 0.0001) 
    {
        x = c / a;
        y = (line.c - line.a * x) / line.b;
    // Special case: second line is vertical (line.a != 0, line.b = 0)
    } else if(abs(line.b) < 0.0001)     
    {
        x = line.c / line.a;
        y = (c - a * x) / b;
    // General case
    } else
    {
        /**
         * ax + by = c
         * by = c - ax
         * y = (c - ax) / b
         * =====
         * a_1x + b_1y = c_1
         * a_1x + b_1((c - ax) / b) = c_1
         * a_1x + (b_1 * c - b_1 * ax) / b = c_1
         * b * a_1x + b_1 * c - b_1 * ax = b * c_1
         * b * a_1x - b_1 * ax = b * c_1 - b_1 * c
         * x(b * a_1 - b_1 * a) = b * c_1 - b_1 * c
         * x = (b * c_1 - b_1 * c) / (b * a_1 - b_1 * a)
         */
        x = (b * line.c - line.b * c) / (b * line.a - line.b * a);

        /**
         * ax + by = c
         * ax = c - by
         * x = (c - by) / a
         * =====
         * a_1x + b_1y = c_1
         * a_1((c - by) / a) + b_1y = c_1
         * (a_1 * c - a_1 * by) / a + b_1y = c_1
         * a_1 * c - a_1 * by + a * b_1y = a * c_1
         * a * b_1y - a_1 * by = a * c_1 - a_1 * c
         * y(a * b_1 - a_1 * b) = a * c_1 - a_1 * c
         * y = (a * c_1 - a_1 * c) / (a * b_1 - a_1 * b)
         */
        y = (a * line.c - line.a * c) / (a * line.b - line.a * b);
    }

    cout << "The point of intersection is: (" << x << ", " << y << ")." << endl;
}

/**
 * lineType::lineType: Default Constructor
 * @param double value1 - The value to initialize a
 * @param double value2 - The value to initialize b
 * @param double value3 - The value to initialize c
 */
lineType::lineType(double value1, double value2, double value3)
{
    a = value1;
    b = value2;
    c = value3;
}