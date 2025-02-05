// Question 26: Calculate Paint needed for House
/**
 * Given:
 * - One Door, Two Windows, and a Built-In Bookshelf
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int paintGallon = 120;  // Default: 120 square feet
    int totalArea = 0;
    int doorLength = 0;
    int doorWidth = 0;
    int doorArea = 0;
    int windowLength = 0;
    int windowWidth = 0;
    int windowArea = 0;
    int shelfLength = 0;
    int shelfWidth = 0;
    int shelfArea = 0;
    int roomLength = 0;
    int roomWidth = 0;
    int roomHeight = 0;
    int roomArea = 0;
    double totalGallons = 0;
    char select = ' ';

    // Prompt for Area for Paint
    while(true)
    {
        cout << "How much area can 1 gallon of paint cover? ";
        cin >> paintGallon;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
        {
            break;
        }
    }

    // Prompt for User Input
    while(true)
    {
        // Prompt for Door Metrics
        cout << "Do you want to paint the door? (y/n): ";
        cin >> select;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        }
        
        if(select == 'y')
        {
            cout << "Enter the length and width of the door: ";
            cin >> doorLength >> doorWidth;
            if(cin.fail() || doorLength <= 0 || doorWidth <= 0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter two non-zero integer values." << endl;
                continue;
            }
            doorArea = doorLength * doorWidth;
        }

        // Prompt for Window Metrics
        select = ' ';
        cout << "Do you want to paint the windows? (y/n): ";
        cin >> select;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        }
        
        if(select == 'y')
        {
            cout << "Enter the length and width of the window: ";
            cin >> windowLength >> windowWidth;
            if(cin.fail() || windowLength <= 0 || windowWidth <= 0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter two non-zero integer values." << endl;
                cout << "Use Case: 'length' 'width'" << endl;
                continue;
            }
            windowArea = windowLength * windowWidth;
        }

        // Prompt for Book Shelf Metrics
        select = ' ';
        cout << "Do you want to paint the bookshelf? (y/n): ";
        cin >> select;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 'y' or 'n'." << endl;
        }
        
        if(select == 'y')
        {
            cout << "Enter the length and width of the bookshelf: ";
            cin >> shelfLength >> shelfWidth;
            if(cin.fail() || shelfLength <= 0 || shelfWidth <= 0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter two non-zero integer values." << endl;
                cout << "Use Case: 'length' 'width'" << endl;
                continue;
            }
            shelfArea = shelfLength * shelfWidth;
        }

        cout << "Enter the length, width and height of the room: ";
        cin >> roomLength >> roomWidth >> roomHeight;
        if(cin.fail() || roomLength <= 0 || roomWidth <= 0 || roomHeight <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter three non-zero integer values." << endl;
            cout << "Use Case: 'length' 'width' 'height'" << endl;
        } else {
            break;
        }
    }
    
    // Calculate room area (walls + ceiling)
    roomArea = (2 * roomLength * roomHeight) +  // front and back walls
               (2 * roomWidth * roomHeight) +   // side walls
               (roomLength * roomWidth);        // ceiling
    // Subtract areas that don't need paint
    totalArea = roomArea - doorArea - windowArea - shelfArea;
    // Calculate total gallons needed (rounded up)
    totalGallons = ceil(static_cast<double>(totalArea) / static_cast<double>(paintGallon));

    // Display Results
    cout << "***************" << endl;
    cout << "* 1 Gallon of paint can cover is " << paintGallon << " ft^2." << endl;
    if(doorArea > 0)
    {
        cout << "* The area to cover the door is " << doorArea << " ft^2." << endl;
    }
    if(windowArea > 0)
    {
        cout << "* The area to cover two windows is " << windowArea  << " ft^2." << endl;
    }
    if(shelfArea > 0)
    {
        cout << "* The area to cover the bookshelf is " << shelfArea  << " ft^2." << endl;
    }
    cout << "* Total wall and ceiling area: " << roomArea << " ft^2." << endl;
    cout << "* Total area to be painted: " << totalArea << " ft^2." << endl;
    cout << "* " << totalGallons << " gallons of paint needed to paint the room." << endl;
    cout << "***************" << endl;

    return 0;
}