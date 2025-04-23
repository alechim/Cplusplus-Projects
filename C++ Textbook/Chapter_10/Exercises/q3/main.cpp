// Question 3: houseType Class Program
#include <iostream>
#include <iomanip>
#include "houseType.h"

using namespace std;

int main()
{
    // Variables - House Objects
    houseType house1("Ranch", 3, 2, 2, 2005, 1800, 185000, 3600.0);
    houseType house2;       // Using default constructor
    
    // Display Initial Information
    cout << "\n+===== Initial House Information =====" << endl;
    cout << "| House 1" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    house1.print();
    
    cout << endl << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    cout << "| House 2 (default values)" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    house2.print();
    
    // Set Values for house2
    house2.set("Colonial", 4, 3, 2, 1995, 2400, 275000, 4800.0);
    
    cout << endl << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    cout << "| House 2 (after set)" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    house2.print();
    
    // Update house1 Properties
    cout << endl << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    cout << "| Updating House 1..." << endl;
    house1.setFinishedSquareFootage(2000);
    house1.setPrice(210000);
    house1.setTax(3900);
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');

    // Display Updated Information
    cout << endl << "+===== After Updates =====" << endl;
    cout << "| Updated House 1" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    house1.print();
    
    // Create a Third House using Individual Setters
    houseType house3;
    house3.setStyle("Modern");
    house3.setNumOfBedrooms(5);
    house3.setNumOfBathrooms(3);
    house3.setNumOfCarsGarage(3);
    house3.setYearBuilt(2020);
    house3.setFinishedSquareFootage(3200);
    house3.setPrice(450000);
    house3.setTax(6500);
    
    cout << endl << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    cout << "| House 3 (using individual setters)" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    house3.print();
    
    // Demonstrate Getters
    cout << endl << "+===== House Information Using Getters =====" << endl;
    cout << "| House 1 Details" << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    cout << "| Style: " << house1.getStyle() << endl;
    cout << "| Bedrooms: " << house1.getNumOfBedrooms() << endl;
    cout << "| Bathrooms: " << house1.getNumOfBathrooms() << endl;
    cout << "| Garage Capacity: " << house1.getNumOfCarsGarage() << " cars" << endl;
    cout << "| Year Built: " << house1.getYearBuilt() << endl;
    cout << "| Square Footage: " << house1.getFinishedSquareFootage() << " sq ft" << endl;
    cout << "| Price: $" << fixed << setprecision(2) << house1.getPrice() << endl;
    cout << "| Annual Tax: $" << fixed << setprecision(2) << house1.getTax() << endl;
    cout << "+" << setw(31) << setfill('-') << "" << endl << setfill(' ');
    
    return 0;
}