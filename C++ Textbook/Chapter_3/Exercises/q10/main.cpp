// Question 10: Planting Trees in a Yard
/**
 * Given:
 * - Yard Length, Radius, Distance Between Trees
 * Calculations:
 * - 2r + (n - 1)(2r + d) <= L
 * - 2r + 2rn - 2r + dn - d <= L
 * - 2rn + dn - d <= L
 * - n * (2r + d) - d <= L
 * - n <= L + d / (2r + d)
 */
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int yardLength = 0;
    int treeRadius = 0;
    int spaceBetweenTree = 0;
    int noOfTrees = 0;

    // Prompt for Input
    do
    {
        cout << "Please enter the length of the yard: ";
        cin >> yardLength;
        if(cin.fail() || yardLength <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the radius of a fully-grown tree: ";
        cin >> treeRadius;
        if(cin.fail() || treeRadius <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the space required between the trees: ";
        cin >> spaceBetweenTree;
        if(cin.fail() || spaceBetweenTree <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }
        break;
    } while (true);
    
    // Calculations
    noOfTrees = (yardLength + spaceBetweenTree) / (2 * treeRadius + spaceBetweenTree);

    // Display Results
    cout << "The number of trees that can be planted in a " << yardLength << " length yard with " << spaceBetweenTree << " distance between the trees is " << noOfTrees << " trees." << endl; 

    return 0;
}