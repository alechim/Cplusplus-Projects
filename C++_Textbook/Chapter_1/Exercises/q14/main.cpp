// Question 14: Convert Change to Pennies
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Variables
    int change[4];  // Quarters, Dimes, Nickels, Pennies
    int pennies;

    // Open the file
    ifstream iFile;
    string fileName = "mainIn.txt";
    iFile.open(fileName);

    iFile >> change[0] >> change[1] >> change[2] >> change[3];
    pennies = (change[0] * 25) + (change[1] * 10) + (change[2] * 5) + change[3];

    cout << "There are " << change[0] << " Quarters, " << change[1] << " Dimes, " << change[2] << " Nickels, and " << change[3] << " Pennies." << endl;
    cout << "The change in pennies is " << pennies << "." << endl;

    // Close the file
    iFile.close();

    return 0;
}