// Question 3: houseType Class
// Simple House Management Program
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
    cout << "\n===== Initial House Information =====" << endl;
    cout << ">" << setw(10) << "" << "House 1" << setw(10) << "" << "<" << endl;
    house1.print();
    cout << endl;
    
    cout << ">" << setw(7) << "" << "House 2 (default values)" << setw(7) << "" << "<" << endl;
    house2.print();
    cout << endl;
    
    // Set values for house2
    house2.set("Colonial", 4, 3, 2, 1995, 2400, 275000, 4800.0);
    
    cout << ">" << setw(7) << "" << "House 2 (after set)" << setw(7) << "" << "<" << endl;
    house2.print();
    cout << endl;
    
    // Update house1 properties
    cout << "=========================" << endl;
    cout << "- Updating House 1..." << endl;
    house1.setFinishedSquareFootage(2000);
    house1.setPrice(210000);
    house1.setTax(3900);

    // Demonstrate individual property updates
    cout << "===== After Updates =====" << endl;
    // Display updated information
    cout << ">" << setw(10) << "" << "Updated House 1" << setw(10) << "" << "<" << endl;
    house1.print();
    cout << endl;
    
    // Create a third house using individual setters
    houseType house3;
    house3.setStyle("Modern");
    house3.setNumOfBedrooms(5);
    house3.setNumOfBathrooms(3);
    house3.setNumOfCarsGarage(3);
    house3.setYearBuilt(2020);
    house3.setFinishedSquareFootage(3200);
    house3.setPrice(450000);
    house3.setTax(6500);
    
    cout << "> House 3 (using individual setters) <" << endl;
    house3.print();
    cout << endl;
    
    // Demonstrate getters
    cout << "===== House Information Using Getters =====" << endl;
    cout << ">" << setw(10) << "" << "House 1 Details" << setw(10) << "" << "<" << endl;
    cout << "Style: " << house1.getStyle() << endl;
    cout << "Bedrooms: " << house1.getNumOfBedrooms() << endl;
    cout << "Bathrooms: " << house1.getNumOfBathrooms() << endl;
    cout << "Garage Capacity: " << house1.getNumOfCarsGarage() << " cars" << endl;
    cout << "Year Built: " << house1.getYearBuilt() << endl;
    cout << "Square Footage: " << house1.getFinishedSquareFootage() << " sq ft" << endl;
    cout << "Price: $" << fixed << setprecision(2) << house1.getPrice() << endl;
    cout << "Annual Tax: $" << fixed << setprecision(2) << house1.getTax() << endl;
    
    return 0;
}