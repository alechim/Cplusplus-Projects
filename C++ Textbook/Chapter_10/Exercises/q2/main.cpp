// Question 2: productType Class
#include <iostream>
#include <iomanip>
#include "productType.h"

using namespace std;

int main()
{
    // Variables - Class Objects
    productType product1;
    productType product2("Microwave", "M3562", "GeneralPool", 35, 175.00, 0.1);
    productType product3("D1290", 25, 375.00, 0.05);
    productType product4(10, 8.50, 0.2);

    // Display Initial Product Information
    cout << "+" << setw(29) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Initial Product Information |" << endl;
    cout << "+" << setw(29) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << ">" << setw(10) << "" << "Product 1" << setw(10) << "" << "<" << endl;
    product1.print(); 
    cout << endl;
    
    cout << ">" << setw(10) << "" << "Product 2" << setw(10) << "" << "<" << endl;
    product2.print();
    cout << endl;
    
    cout << ">" << setw(10) << "" << "Product 3" << setw(10) << "" << "<" << endl;
    product3.print();
    cout << endl;
    
    cout << ">" << setw(10) << "" << "Product 4" << setw(10) << "" << "<" << endl;
    product4.print();
    cout << endl;
    cout << endl;

    // Demonstrate setter methods
    cout << "+" << setw(29) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Setting product1's information..." << endl;
    product1.set("Headphones", "HP456", "AudioTech", 25, 79.99, 0.15);

    // Update product quantities
    cout << "| Updating product quantities..." << endl;
    product2.updateQuantitiesInStock(-3);
    product3.setQuantitiesInStock(40);
    
    // Change prices and discounts
    cout << "| Updating prices and discounts..." << endl;
    product4.setPrice(949.99);
    product2.setDiscount(0.20);
    cout << "+" << setw(29) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << endl;

    // Display updated product information
    cout << "+" << setw(29) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Updated Product Information |" << endl;
    cout << "+" << setw(29) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << ">" << setw(5) << "" << "Product 1 (after set)" << setw(5) << "" << "<" << endl;
    product1.print();
    cout << endl;
    
    cout << "> Product 2 (after updating stock and discount) <" << endl;
    product2.print();
    cout << endl;
    
    cout << "> Product 3 (after setting new stock) <" << endl;
    product3.print();
    cout << endl;
    
    cout << "> Product 4 (after price change) <" << endl;
    product4.print();
    cout << endl;
    
    // Calculate and display the final prices (price after discount)
    cout << "+" << setw(31) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Final Prices (after Discount) |" << endl;
    cout << "+" << setw(31) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Product 1: $" << fixed << setprecision(2) << product1.getPrice() * (1 - product1.getDiscount()) << endl;
    cout << "| Product 2: $" << fixed << setprecision(2) << product2.getPrice() * (1 - product2.getDiscount()) << endl;
    cout << "| Product 3: $" << fixed << setprecision(2) << product3.getPrice() * (1 - product3.getDiscount()) << endl;
    cout << "| Product 4: $" << fixed << setprecision(2) << product4.getPrice() * (1 - product4.getDiscount()) << endl;
    cout << "+" << setw(31) << setfill('=') << "" << "+" << endl << setfill(' ');

    return 0;
}