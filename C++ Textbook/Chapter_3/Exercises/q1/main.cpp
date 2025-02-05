// Question 1: Input and Output Program
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Variables
    ifstream inFile;
    ofstream outFile;
    string firstName = "";
    string lastName = "";
    string department = "";
    double salary = 0.0;
    double monthlyBonus = 0.0;
    double taxes = 0.0;
    double payCheck = 0.0;
    double distanceTraveled = 0.0;
    double travelTime = 0.0;
    int coffeeSold = 0;
    double coffeeCost = 0.0;

    // Open the files
    inFile.open("inData.txt");
    outFile.open("outData.txt");

    inFile >> firstName >> lastName >> department;
    inFile >> salary >> monthlyBonus >> taxes;
    inFile >> distanceTraveled >> travelTime;
    inFile >> coffeeSold >> coffeeCost;

    payCheck = salary + (salary * (monthlyBonus / 100));
    payCheck = payCheck - (payCheck * (taxes / 100));

    outFile << fixed << showpoint << setprecision(2);
    outFile << "Name: " << firstName << " " << lastName << ", Department: " << department << endl;
    outFile << "Monthly Gross Salary: $" << salary << ", Monthly Bonus: " << monthlyBonus << "%, Taxes: " << taxes << "%" << endl;
    outFile << "Paycheck: $" << payCheck << endl << endl;
    outFile << "Distance Travelled: " << distanceTraveled << " miles, Traveling Time: " << travelTime << " hours" << endl;
    outFile << "Average Speed: " << distanceTraveled / travelTime << " miles per hour" << endl << endl;
    outFile << "Number of Coffee Cups Sold: " << coffeeSold << ", Cost: $" << coffeeCost << " per cup." << endl;
    outFile << "Sales Amount = $" << coffeeSold * coffeeCost;

    // Close the Files
    inFile.close();
    outFile.close();

    return 0;
}