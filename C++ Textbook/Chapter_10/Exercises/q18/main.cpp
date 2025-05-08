// Question 18: lineType Class Program
#include <iostream>
#include "lineType.h"

using namespace std;

// Function Prototypes
void compareLines(lineType, lineType);

int main()
{
    // Test parallel lines
    lineType line1(2, 3, 6);        // 2x + 3y = 6
    lineType line2(4, 6, 18);       // 4x + 6y = 18
    // Should be parallel
    compareLines(line1, line2);

    // Test perpendicular lines
    lineType line3(3, 4, 5);        // 3x + 4y = 5
    lineType line4(-4, 3, 2);       // -4x + 3y = 2
    // Should be perpendicular and intersect at (0.28, 1.04)
    compareLines(line3, line4);

    // Test intersection
    lineType line5(1, 1, 5);        // x + y = 5
    lineType line6(2, -1, 0);       // 2x - y = 0
    // Should intersect at (1.66667, 3.33333)
    compareLines(line5, line6);

    // Test special cases
    lineType line7(1, 0, -3);       // x = -3 (vertical line)
    lineType line8(0, 1, -4);       // y = -4 (horizontal line)
    // Should be perpendicular and intersect at (-3, -4)
    compareLines(line7, line8);
    cout << endl;

    return 0;
}

/**
 * compareLines: Runs the tests on determining the two lines properties
 * @param lineType line1 - Reference to the first line class object
 * @param lineType line2 - Reference to the second line class object
 */
void compareLines(lineType line1, lineType line2)
{
    cout << endl;

    // Check if we determine slopes for line 1 and 2
    if(line1.getA() == 0 || line1.getB() == 0)
        cout << "The first line is vertical, cannot determine slope." << endl;
    else
        cout << "Slope 1: " << line1.determineSlope() << endl;

    if(line2.getA() == 0 || line2.getB() == 0)
        cout << "The second line is vertical, cannot determine slope." << endl;
    else
        cout << "Slope 2: " << line2.determineSlope() << endl;

    // Determine if two lines are equal
    if(line1.determineEqualLines(line2))
        cout << "Both lines are equal." << endl;
    else
        cout << "Both lines are not equal." << endl;

    // Determine if two lines are parallel
    if(line1.determineParallelLines(line2))
        cout << "Both lines are parallel to each other." << endl;
    else
    {
        cout << "Both lines are not parallel to each other." << endl;

        // Determine if two lines are perpendicular
        if(line1.determinePerpendicularLines(line2))
            cout << "Both lines are perpendicular to each other." << endl;
        else
            cout << "Both lines are not perpendicular to each other." << endl;
        
        // If two lines are not parallel, find the point of intersection
        line1.pointOfIntersection(line2);
    }
}