#include <iostream>
#include <iomanip>
#include <cmath>
#include "swimmingPool.h"

using namespace std;

// Class Function Definitions
/**
 * swimmingPool::determineTimeFill: Determines the time needed to completely or partially fill the pool and add water from the pool
 */
void swimmingPool::determineTimeFill()
{
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
    if(currentWater == 1.0)
    {
        cout << "| The pool is currently full, cannot add more water." << endl;
        cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
        return;
    }

    // 7.5 gallons per cubic foot
    double volume = length * width * depth * 7.5;

    cout << "| Filling the Pool" << endl;
    double amount = promptAmount();
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
    if(amount + currentWater > 1.0)
    {
        cout << "| The requested amount of water to fill exceeds the total amount within the pool." << endl;
        cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
        amount = 1.0 - currentWater;
    }

    cout << "| Filling";
    if(amount == 1.0)
        cout << " the max amount of water ";
    else if(amount == 0.25)
        cout << " 1/4 of water ";
    else if(amount == 0.5)
        cout << " 1/2 of water ";
    else if(amount == 0.75)
        cout << " 3/4 of water ";
    cout << "into the pool." << endl;

    // Calculate the time needed to drain the pool in minutes
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Time it took to fill the pool: " << round((volume * amount) / fillingPool) << " minutes." << endl;
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');

    currentWater += amount;
    if(currentWater > 0.999)    currentWater = 1.0;
}

/**
 * swimmingPool::determineTimeDrain: Determines the time needed to completely or partially empty the pool and drain water from the pool
 */
void swimmingPool::determineTimeDrain()
{
    cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
    if(currentWater == 0.0)
    {
        cout << "| The pool is currently empty, cannot drain more water." << endl;
        cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
        return;
    }
    
    // 7.5 gallons per cubic foot
    double volume = length * width * depth * 7.5;

    cout << "| Draining the Pool" << endl;
    double amount = promptAmount();
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
    if(amount > currentWater)
    {
        cout << "| The requested amount of water to drain exceeds the total amount from the pool." << endl;
        cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
        amount = currentWater;
    }

    cout << "| Draining";
    if(amount == currentWater || amount == 1.0)
        cout << " all of the water ";
    else if(amount == 0.25)
        cout << " 1/4 of water ";
    else if(amount == 0.5)
        cout << " 1/2 of water ";
    else if(amount == 0.75)
        cout << " 3/4 of water ";
    cout << "from the pool." << endl;

    // Calculate the time needed to drain the pool in minutes
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << "| Time it took to drain the pool: " << round((volume * amount) / drainingPool) << " minutes." << endl;
    cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');

    currentWater -= amount;
    if(currentWater < 0.001)    currentWater = 0.0;
}

/**
 * swimmingPool::promptAmount: Displays a prompt for the user to enter how much of the pool they want filled/drained
 * @return double - The amount to be filled/drained
 */
double swimmingPool::promptAmount()
{
    int choice = 0;

    cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| [1] 1/4 of the water" << setw(3) << "" << "|" << endl;
    cout << "| [2] 1/2 of the water" << setw(3) << "" << "|" << endl;
    cout << "| [3] 3/4 of the water" << setw(3) << "" << "|" << endl;
    cout << "| [4] All of the water" << setw(3) << "" << "|" << endl;
    cout << "+" << setw(24) << setfill('=') << "" << "+" << endl << setfill(' ');
    do
    {
        cout << "| Please enter one of the above choices: ";
        cin >> choice;
        if(cin.fail() || choice < 1 || choice > 4)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| Invalid Input! Please enter a valid choice." << endl;
            cout << "+" << setw(24) << setfill('-') << "" << "+" << endl << setfill(' ');
        } else
            break;
    } while(true);

    switch(choice)
    {
        case 1:
            return 0.25;
        case 2:
            return 0.5;
        case 3:
            return 0.75;
        case 4:
            return 1.0;
        default: 
            return 1.0;
    }
}

/**
 * swimmingPool::displayWater: Outputs a message based on the instance variable, currentWater, from the pool
 */
void swimmingPool::displayWater()
{
    if(currentWater == 1.0)
    {
        cout << "| The pool is currently full." << endl;
        return;
    }

    cout << "| There is currently";

    if(currentWater == 0.0)
        cout << " no water ";
    else if(currentWater == 0.25)
        cout << " 1/4 of water ";
    else if(currentWater == 0.5)
        cout << " 1/2 of water ";
    else if(currentWater == 0.75)
        cout << " 3/4 of water ";

    cout << "within the pool." << endl;
}

/**
 * swimmingPool::swimmingPool: Default Constructor
 * @param double poolLength - The length of the pool in feet
 * @param double poolWidth - The width of the pool in feet
 * @param double poolDepth - The depth of the pool in feet
 * @param double rateFill - The rate at which the pool will fill in gallons per minute
 * @param double rateDrain - The rate at which the pool will drain in gallons per minute
 */
swimmingPool::swimmingPool(double poolLength, double poolWidth, double poolDepth, double rateFill, double rateDrain)
{
    length = poolLength;
    width = poolWidth;
    depth = poolDepth;
    fillingPool = rateFill;
    drainingPool = rateDrain;
    currentWater = 0.0;
}