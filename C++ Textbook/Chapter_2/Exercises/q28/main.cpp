// Question 28: Distribute Snacks
/**
 * Given:
 * - 1 lb of nuts = 0.7 * 1 lb of dried fruit
 * - 1 lb of fruits = 1 lb nuts / 0.7
 * Calculations:
 * - Let x = # of nuts and y = # of fruits
 *   > x = 0.7y
 * - caloriePerKid = x * caloriePerNut + y * caloriePerFruit
 * - caloriePerKid = 0.7y * caloriePerNut + y * caloriePerFruit
 * - caloriePerKid = y(0.7 * caloriePerNut + caloriePerFruit)
 * - y = caloriePerKid / (0.7 * caloriePerNut + caloriePerFruit)
 */
/**
 * Algorithm:
 * - Prompt User Input
 *   > # of kids, # of calories needed per kid, and # of calories per nuts
 * - Output # of nuts and dried fruits needed per person
 */
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    int noOfNuts = 0;
    int noOfFruit = 0;
    int noOfKids = 0;
    int caloriePerKid = 0;
    int caloriePerNut = 0;
    int caloriePerFruit = 0;
    int remainingCalories = 0;

    // Prompt for Input
    while(true)
    {
        cout << "Please enter the number of elementary students: ";
        cin >> noOfKids;
        if(cin.fail() || noOfKids <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Please enter the number of calories required for each student: ";
        cin >> caloriePerKid;
        if(cin.fail() || caloriePerKid <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }
        
        cout << "Please enter the number of calories per 1 lb of nuts: ";
        cin >> caloriePerNut;
        if(cin.fail() || caloriePerNut <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }
        break;
    }

    // Calculations
    caloriePerFruit = round(caloriePerNut / 0.7);
    noOfFruit = caloriePerKid / caloriePerFruit;
    remainingCalories = caloriePerKid - (noOfFruit * caloriePerFruit);
    if(remainingCalories > 0)
    {
        noOfNuts = ceil(static_cast<double>(remainingCalories) / caloriePerNut);
    }

    // Display Results
    cout << "***************" << endl;
    cout << "* The " << noOfKids << " elementary schoolers each need to consume " << caloriePerKid << " calories." << endl;
    cout << "* Each kid should receive " << noOfFruit << " dried fruits and " << noOfNuts << " nuts as snacks." << endl;
    cout << "* Each pound of fruit contains: " << caloriePerFruit << " calories." << endl;
    cout << "* Each pound of nuts contains: " << caloriePerNut << " calories." << endl;
    cout << "* Total calories provided: " << (noOfNuts * caloriePerNut + noOfFruit * caloriePerFruit) << endl;
    cout << "***************" << endl;

    return 0;
}