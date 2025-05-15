// Question 13: Characters and Lines on a Paper
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    double length = 0.0;
    double width = 0.0;
    double margins[4];      // 0: top, 1: bottom, 2: left, 3: right
    double pointSize = 0.0;
    char choice = ' ';
    int charsPerLine = 0;
    int numOfLines = 0;

    // Input Validation
    do
    {
        cout << "Enter the length and width of the paper: ";
        cin >> length >> width;
        if(cin.fail() || length <= 0 || width <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 2 non-zero positive double values." << endl;
        }

        cout << "Enter the top, bottom, left, and right margins of the paper: ";
        cin >> margins[0] >> margins[1] >> margins[2] >> margins[3];
        if(cin.fail() || margins[0] < 0 || margins[1] < 0 || margins[2] < 0 || margins[3] < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 4 positive double values." << endl;
        }

        cout << "Enter the point size of a line: ";
        cin >> pointSize;
        if(cin.fail() || pointSize <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        }

        cout << "Are the lines double spaced? (y/n): ";
        cin >> choice;
        if(cin.fail() || (choice != 'y' && choice != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    // - 1 inch = 72 points
    double availableWidth = width - (margins[2] + margins[3]);
    double availableLength = length - (margins[0] + margins[1]);
    double characterWidth = pointSize / 72.0;
    double lineHeight = pointSize / 72.0;      // If the lines are double-spaced, then double the point size of each character
    if(choice == 'y')
        lineHeight *= 2.0;
    charsPerLine = static_cast<int>(availableWidth / characterWidth);
    numOfLines = static_cast<int>(availableLength / lineHeight);

    // Display Results
    cout << "===== Results =====" << endl;
    cout << "The number of characters that can be printed on each line is " << charsPerLine << " characters." << endl;
    cout << "The number of lines on the paper is " << numOfLines << " lines." << endl;

    return 0;
}