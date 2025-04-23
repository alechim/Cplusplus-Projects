#include <iostream>
#include "wkp4Def.hpp"

using namespace std;

int main()
{
    // Variables
    myClass mClass;
    int x = 0, y = 0;

    // Prompt for Input
    cout << "Enter the first number: ";
    cin >> x;

    cout << "Enter the second number: ";
    cin >> y;

    // Set the values to the class and print results
    mClass.set(x, y);
    mClass.print();

    // Check if equal and perform calculations
    if(mClass.equal())
        cout << "Both numbers are equal to each other." << endl;
    else
        cout << "Total: " << mClass.compute(x) << endl;

    return 0;
}