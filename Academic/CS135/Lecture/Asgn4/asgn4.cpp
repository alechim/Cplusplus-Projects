/* Alec Him, 2001543593, CS135 1004, Assignment 4
 * Description: Calculates dimensions of Star Shapes
 * Input: Length, Base Length, Edge Length, Inner Angle, Point Count, Outer Angle
 * Output: Height, Lateral Surface, Area, Volume, Focal Point, Gain 
 */
#include <iostream>     // For console input and output
#include <cmath>        // Gives the program access to sin(), sqrt(), pow(), etc.
#include <iomanip>      // For formatting

using namespace std;

int main()
{
    // Variables
    const double PI = 3.141592653589793;
    char c = ' ';

    // Variables - Double Star Polygon
    double height = 0.0;
	double length = 0.0;
	double base = 0.0;
	double diameter = 0.0;
	double heightLong = 0.0;
	double heightShort = 0.0;
	double perimeter = 0.0;
	double lengthShort = 0.0;
	double lengthLong = 0.0;
	double area = 0.0;

    // Variables - Threestar Polygon
    double outerAngle = 0.0;
	double innerAngle = 0.0;
	double spikeBase = 0.0;
	double edgeLength = 0.0;
	double spikeHeight = 0.0;
	double chordLength = 0.0;

    // Variables - Polygram
    double pointCount = 0.0;
	double baseLength = 0.0;

    cout << "\n****************************************" << endl;
	cout << "*  Rebel Alliance Computation Support  *" << endl;
	cout << "*  Star Area Calculator                *" << endl;
	cout << "****************************************" << endl;

    do
    {
        // Prompt for Input
        cout << "\n(d/D/2) - Double Star Polygon" << endl;
        cout << "(t/T/3) - Three Star Polygon" << endl;
        cout << "(p/P) - Polygram Polygon" << endl;
        cout << "(q/Q) - Quit" << endl;
        cout << "\nYour Selection: ";
        cin >> c;

        switch(c)
        {
            case 'd':
            case 'D':
            case '2':
                cout << "\nDouble Star Polygon Calculator" << endl;
                cout << "------------------------------\n" << endl;
                
                // Prompt for Input
                cout << "Length Long Valid Range [1.00 < Length Long < 236.00]" << endl;
                cout << "Length Long: ";
			    cin >> lengthLong;

                if(1.00 < lengthLong && lengthLong < 236.00)
                {
                    cout << "Length Short Valid Range [1.00 < Length Short < 118.00]" << endl;
                    cout << "Length Short: ";
                    cin >> lengthShort;
                }

                if(1.00 < lengthShort && lengthShort < 118.00)
                {
                    cout << "Base Length Valid Range [1.00 < Base Short < 29.50]" << endl;
                    cout << "Base: ";
                    cin >> base;
                }

                // Display Results
                if(1.00 < base && base < 29.50)
                {
                    cout << "--------------------------------------" << endl;
                    cout << "Calculations for a Double Star Polygon" << endl;

                    // Calculations
                    height = sqrt(pow(length, 2.0) - pow(base, 2.0) / 4.0);
                    heightLong = sqrt(pow(lengthLong, 2.0) - pow(base, 2.0) / 4.0);
                    heightShort = sqrt(pow(lengthShort, 2.0) - pow(base, 2.0) / 4.0);
                    length = sqrt(pow(height, 2.0) + pow(base, 2.0) / 4.0);
                    diameter = 2 * heightLong + base * (1 + sqrt(2));
                    perimeter = 8 * (lengthShort + lengthLong);
                    area = 2 * base * (base * (1 + sqrt(2)) + (heightLong + heightShort));

                    // Display Results
                    cout << "Base Length: " << fixed << setprecision(2) << base << endl;
                    cout << "Length Long: " << fixed << setprecision(2) << lengthLong << endl;
                    cout << "Length Short: " << fixed << setprecision(2) << lengthShort << endl;
                    cout << "--------------------------------------" << endl;
                    cout << "Height Long: " << heightLong << endl;
                    cout << "Height Short: " << heightShort << endl;
                    cout << "Diameter: " << diameter << endl;
                    cout << "Perimeter: " << perimeter << endl;
                    cout << "Area: " << area << endl;
                }

                break;
            case 't':
            case 'T':
            case '3':
                cout << "\nThreestar Polygon Calculator:" << endl;
                cout << "-----------------------------\n" << endl;

                // Prompt for Input
                cout << "Edge Length Valid Range [1.00 < Edge Length < 132.00]" << endl;
                cout << "Edge Length: ";
                cin >> edgeLength;

                if (1.00 < edgeLength && edgeLength < 132.00)
                {
                    cout << "Inner Angle (Degrees) Valid Range [0.00 < Inner Angle < 60.00]" << endl;
                    cout << "Inner Angle (Degrees): ";
                    cin >> innerAngle;
                }

                // Display Results
                if (0.00 < innerAngle && innerAngle < 60.00)
                {
                    cout << "------------------------------------" << endl;
                    cout << "Calculations for a Threestar Polygon" << endl;
                    
                    // Calculations
                    outerAngle = 120 + edgeLength;
                    spikeBase = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(edgeLength * PI / 180)));
                    spikeHeight = sqrt((4 * pow(edgeLength, 2.0) - pow(spikeBase, 2.0)) / 4.0);
                    chordLength = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(outerAngle * PI / 180)));
                    height = sqrt(3) / 2 * chordLength;
                    perimeter = 6 * edgeLength;
                    area = 3.0/2.0 * spikeHeight * spikeBase + sqrt(3)/4 * pow(spikeBase, 2.0);

                    // Display Results
                    cout << "Edge Length: " << fixed << setprecision(2) << edgeLength << endl;
                    cout << "Outer Angle: " << fixed << setprecision(2) << outerAngle << endl;
                    cout << "Inner Angle: " << fixed << setprecision(2) << innerAngle << endl;
                    cout << "------------------------------------" << endl;
                    cout << "Spike Base: " << spikeBase << endl;
                    cout << "Spike Height: " << spikeHeight << endl;
                    cout << "Chord Length: " << chordLength << endl;
                    cout << "Height: " << height << endl;
                    cout << "Perimeter: " << perimeter << endl;
                    cout << "Area: " << area << endl;
                }

                break;
            case 'p':
            case 'P':
                cout << "\nPolygram Calculator" << endl;
                cout << "------------------------------\n" << endl;

                // Prompt for Input
                cout << "Point Count Valid Range [3.00 < Point Count < 100.00]" << endl;
                cout << "Point Count: ";
			    cin >> pointCount;

                if(3.00 < pointCount && pointCount < 100.00)
                {
                    cout << "Edge Length Valid Range [1.00 < Edge Length < 132.00]" << endl;
                    cout << "Edge Length: ";
                    cin >> edgeLength;
                }

                if(1.00 < edgeLength && edgeLength < 132.00)
                {
                    cout << "Outer Angle Valid Range [0.00 < Outer Angle < 60.00]" << endl;
                    cout << "Outer Angle: ";
                    cin >> outerAngle;
                }

                if(0.00 < outerAngle && outerAngle < 60.00)
                {
                    cout << "-------------------------" << endl;
                    cout << "Calculations for Polygram" << endl;

                    // Calculations
                    innerAngle = ((outerAngle * PI / 180) - (2 * PI) / pointCount) * (180 / PI);
                    baseLength = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(innerAngle * PI / 180)));
                    spikeHeight = sqrt((4 * pow(edgeLength, 2.0) - pow(baseLength, 2.0)) / 4.0);
                    chordLength = sqrt(2 * pow(edgeLength, 2.0) * (1 - cos(outerAngle * PI / 180)));
                    perimeter = 2 * pointCount * edgeLength;
                    area = pointCount * pow(baseLength, 2.0) / (4 * tan(PI / pointCount)) + pointCount * spikeHeight * baseLength / 2.0;

                    // Display Results
                    cout << "Point Count: " << pointCount << endl;
                    cout << "Edge Length: " << fixed << setprecision(2) << edgeLength << endl;
                    cout << "Outer Angle: " << fixed << setprecision(2) << outerAngle << endl;
                    cout << "-------------------------" << endl;
                    cout << "Inner Angle: " << innerAngle << endl;
                    cout << "Base Length: " << baseLength << endl;
                    cout << "Chord Length: " << chordLength << endl;
                    cout << "Spike Height: " << spikeHeight << endl;
                    cout << "Perimeter: " << perimeter << endl;
                    cout << "Area: " << area << endl;
                }

                break;
            case 'q':
            case 'Q':
                break;
            default:
                cout << "\nError - Invalid Entry" << endl;
        }
        if(c == 'q' || c == 'Q')
            break;
    } while(true);

    cout << "\nThank you for using Rebel Alliance Computational Support" << endl;
	cout << "May the Force be with you!" << endl;

	cout << "            x            " << endl;
	cout << "      x    xxx    x      " << endl;
	cout << "     x    x x x    x     " << endl;
	cout << "    x      xxx      x    " << endl;
	cout << "   xx       x       xx   " << endl;
	cout << "  xxx      xxx      xxx  " << endl;
	cout << "  xxxx     xxx     xxxx  " << endl;
	cout << "  xxxxx    xxx    xxxxx  " << endl;
	cout << "   xxxxxxxxxxxxxxxxxxx   " << endl;
	cout << "    xxxxxxxxxxxxxxxxx    " << endl;
	cout << "     xxxxxxxxxxxxxxx     " << endl;
	cout << "      xxxxxxxxxxxxx      " << endl;

    return 0;
}