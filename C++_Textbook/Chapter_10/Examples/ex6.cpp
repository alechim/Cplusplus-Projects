// Example 10-6: Constructor Usages
#include <iostream>

using namespace std;

// Classes
class inventory
{
    public:
        inventory();
        inventory(string);
        inventory(string, int, double);
        inventory(string, int, double, int);

    private: 
        string name;
        int itemNum;
        double price;
        int unitsInStock;
};

int main()
{
    inventory item1;
    inventory item2("Dryer");
    inventory item3("Washer", 2345, 278.95);
    inventory item4("Toaster", 8231, 34.49, 200);

    return 0;
}

// Class Function Definitions
/**
 * inventory::inventory: the default constructor
 */
inventory::inventory()
{
    name = "";
    itemNum = -1;
    price = 0.0;
    unitsInStock = 0;
}

/**
 * inventory::inventory: Constructor initializing only name
 * @param string n - The name of the item
 */
inventory::inventory(string n)
{
    name = n;
    itemNum = -1;
    price = 0.0;
    unitsInStock = 0;
}

/**
 * inventory::inventory: Constructor initializing name, itemNum, and price
 * @param string n - The name of the item
 * @param int iNum - The ID of the item
 * @param double cost - The cost of the item
 */
inventory::inventory(string n, int iNum, double cost)
{
    name = n;
    itemNum = iNum;
    price = cost;
    unitsInStock = 0;
}

/**
 * inventory::inventory: Constructor initializing all 4 parameters
 * @param string n - The name of the item
 * @param int iNum - The ID of the item
 * @param double cost - The cost of the item
 * @param int inStock - The number of stock of the item
 */
inventory::inventory(string n, int iNum, double cost, int inStock)
{
    name = n;
    itemNum = iNum;
    price = cost;
    unitsInStock = inStock;
}