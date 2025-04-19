#include <iostream>
#include <iomanip>
#include "productType.h"

using namespace std;

// Class Function Definitions
/**
 * productType::productType: Default Constructor
 */
productType::productType()
{
    productName = "";
    id = "";
    manufacturer = "";
    quantitiesInStock = 0;
    price = 0.0;
    discount = 0.0;
}

/**
 * productType::productType: Constructor with 3 parameters
 * @param int stock - The initial quantity of the product in stock
 * @param double cost - The price of the product
 * @param double sale - The discount percentage as a decimal
 */
productType::productType(int stock, double cost, double sale)
{
    productName = "";
    id = "";
    manufacturer = "";
    quantitiesInStock = ((stock >= 0) ? stock : 0);
    price = ((cost >= 0.0) ? cost : 0.0);
    discount = ((sale >= 0.0) ? sale : 0.0);
}

/**
 * productType::productType: Constructor with 4 parameters
 * @param string ID - The product identifier code
 * @param int stock - The initial quantity of the product in stock
 * @param double cost - The price of the product
 * @param double sale - The discount percentage as a decimal
 */
productType::productType(string ID, int stock, double cost, double sale)
{
    productName = "";
    id = ID;
    manufacturer = "";
    quantitiesInStock = ((stock >= 0) ? stock : 0);
    price = ((cost >= 0.0) ? cost : 0.0);
    discount = ((sale >= 0.0) ? sale : 0.0);
}

/**
 * productType::productType: Constructor with all the parameters
 * @param string product - The name of the product
 * @param string ID - The product identifier code
 * @param string creator - The manufacturer of the product
 * @param int stock - The initial quantity of the product in stock
 * @param double cost - The price of the product
 * @param double sale - The discount percentage as a decimal
 */
productType::productType(string product, string ID, string creator, int stock, double cost, double sale)
{
    productName = product;
    id = ID;
    manufacturer = creator;
    quantitiesInStock = ((stock >= 0) ? stock : 0);
    price = ((cost >= 0.0) ? cost : 0.0);
    discount = ((sale >= 0.0) ? sale : 0.0);
}

/**
 * productType::set: Sets all the product information at once
 * @param string product - The name of the product
 * @param string ID - The product identifier code
 * @param string creator - The manufacturer of the product
 * @param int stock - The initial quantity of the product in stock
 * @param double cost - The price of the product
 * @param double sale - The discount percentage as a decimal
 */
void productType::set(string product, string ID, string creator, int stock, double cost, double sale)
{
    productName = product;
    id = ID;
    manufacturer = creator;
    quantitiesInStock = ((stock >= 0) ? stock : 0);
    price = ((cost >= 0.0) ? cost : 0.0);
    discount = ((sale >= 0.0) ? sale : 0.0);
}

/**
 * productType::print const: Displays all product information to console
 */
void productType::print() const
{
    cout << left << setw(16) << "Product Name: " << productName << endl;
    cout << left << setw(16) << "Product ID: " << id << endl;
    cout << left << setw(16) << "Manufacturer: " << manufacturer << endl;
    cout << left << setw(16) << "Stock: " << quantitiesInStock << endl;
    cout << left << setw(16) << "Price: " << "$" << fixed << showpoint << setprecision(2) << price << endl;
    cout << left << setw(16) << "Discount: " << discount << endl; 
}

/**
 * productType::setQuantitiesInStock: Sets the quantity in stock to the specified value
 * @param int x - The new quantity value
 */
void productType::setQuantitiesInStock(int x)
{
    quantitiesInStock = x;
}

/**
 * productType::updateQuantitiesInStock: Adjusts the quantity in stock by the specified amount
 * @param int x - The amount to add to the current stock (can be negative)
 */
void productType::updateQuantitiesInStock(int x)
{
    quantitiesInStock += x;
}

/**
 * productType::getQuantitiesInStock const: Returns the current quantity in stock
 * @return int - The current quantity in stock
 */
int productType::getQuantitiesInStock() const
{
    return quantitiesInStock;
}

/**
 * productType::setPrice: Sets the price to the specified value
 * @param double x - The new price value
 */
void productType::setPrice(double x)
{
    price = x;
}

/**
 * productType::getPrice const: Returns the current price
 * @return double - The current price
 */
double productType::getPrice() const
{
    return price;
}

/**
 * productType::setDiscount: Sets the discount to the specified value
 * @param double d - The new discount value
 */
void productType::setDiscount(double d)
{
    discount = d;
}

/**
 * productType::getDiscount const: Returns the current discount
 * @return double - The current discount
 */
double productType::getDiscount() const
{
    return discount;
}