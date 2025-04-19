#include <iostream>
#include <iomanip>
#include "houseType.h"

using namespace std;

// Class Function Definitions
/**
 * houseType::set: Sets all the properties of the house at once
 * @param string houseStyle - The style of the house
 * @param int bedroom - The number of bedrooms in the house
 * @param int bathroom - The number of bathrooms in the house
 * @param int garage - The number of cars the garage can hold
 * @param int year - The year the house was built
 * @param int sqFoot - The finished square footage of the house
 * @param double housePrice - The price of the house
 * @param double houseTax - The annual tax amount for the house
 */
void houseType::set(string houseStyle, int bedroom, int bathroom, int garage, int year, int sqFoot, double housePrice, double houseTax)
{
    style = houseStyle;
    numOfBedrooms = bedroom;
    numOfBathrooms = bathroom;
    numOfCarsGarage = garage;
    yearBuilt = year;
    finishedSquareFootage = sqFoot;
    price = housePrice;
    tax = houseTax;
}

/**
 * houseType::print const: Displays all house information to console
 */
void houseType::print() const
{
    cout << left << setw(25) << "Style of House: " << style << endl;
    cout << left << setw(25) << "Number of Bathrooms: " << numOfBedrooms << endl;
    cout << left << setw(25) << "Number of Bedrooms: " << numOfBedrooms << endl;
    cout << left << setw(25) << "Number of Car Garage: " << numOfCarsGarage << endl;
    cout << left << setw(25) << "Year Built: " << yearBuilt << endl;
    cout << left << setw(25) << "Finished Square Footage: " << finishedSquareFootage << endl;
    cout << left << setw(25) << "Price of House: " << "$" << fixed << showpoint << setprecision(2) << price << endl;
    cout << left << setw(25) << "House Tax: " << tax << endl;
}

/**
 * +=== Class Setters and Getters ===+
 */
void houseType::setStyle(string x) { style = x; }
string houseType::getStyle() const { return style; }

void houseType::setNumOfBedrooms(int x) { numOfBedrooms = x; }
int houseType::getNumOfBedrooms() const { return numOfBedrooms; }

void houseType::setNumOfBathrooms(int x) { numOfBathrooms = x; }
int houseType::getNumOfBathrooms() const{ return numOfBathrooms; }

void houseType::setNumOfCarsGarage(int x) { numOfCarsGarage = x; }
int houseType::getNumOfCarsGarage() const { return numOfCarsGarage; }

void houseType::setYearBuilt(int x) { yearBuilt = x; }
int houseType::getYearBuilt() const { return yearBuilt; }

void houseType::setFinishedSquareFootage(int x) { finishedSquareFootage = x; }
int houseType::getFinishedSquareFootage() const { return finishedSquareFootage; }

void houseType::setPrice(double x) { price = x; }
double houseType::getPrice() const { return price; }

void houseType::setTax(double x) { tax = x; }
double houseType::getTax() const { return tax; }

/**
 * houseType::houseType: Default Constructor 
 * - If one parameter is not specified, initialized to default values (0, 0.0, or "")
 * @param string houseStyle - The style of the house
 * @param int bedroom - The number of bedrooms in the house
 * @param int bathroom - The number of bathrooms in the house
 * @param int garage - The number of cars the garage can hold
 * @param int year - The year the house was built
 * @param int sqFoot - The finished square footage of the house
 * @param double housePrice - The price of the house
 * @param double houseTax - The annual tax amount for the house
 */
houseType::houseType(string houseStyle, int bedroom, int bathroom, int garage, int year, int sqFoot, double housePrice, double houseTax)
{
    style = houseStyle;
    numOfBedrooms = bedroom;
    numOfBathrooms = bathroom;
    numOfCarsGarage = garage;
    yearBuilt = year;
    finishedSquareFootage = sqFoot;
    price = housePrice;
    tax = houseTax;
}