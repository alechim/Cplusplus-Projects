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
 * inventory::inventory: 
 * @param string n - 
 */
inventory::inventory(string n)
{
    name = n;
    itemNum = -1;
    price = 0.0;
    unitsInStock = 0;
}

/**
 * inventory::inventory: 
 * @param string n - 
 * @param int iNum -
 * @param double cost - 
 */
inventory::inventory(string n, int iNum, double cost)
{
    name = n;
    itemNum = iNum;
    price = cost;
    unitsInStock = 0;
}

/**
 * inventory::inventory: 
 * @param string n - 
 * @param int iNum -
 * @param double cost - 
 * @param int inStock - 
 */
inventory::inventory(string n, int iNum, double cost, int inStock)
{
    name = n;
    itemNum = iNum;
    price = cost;
    unitsInStock = inStock;
}