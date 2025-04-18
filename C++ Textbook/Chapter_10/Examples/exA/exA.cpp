// Example 10-A: Juice Machine
/** 
 * Usage: 
 * - 1st: Object Code File `g++ -c juiceMachine.cpp`
 * - 2nd: Executable Code File `g++ exA.cpp juiceMachine.o -o exA`
 * - 3rd: Run executable `.\exA`
 */
#include <iostream>
#include "juiceMachine.h"

using namespace std;

// Function Prototypes
void showSelection();
void sellProduct(dispenserType&, cashRegister&);

int main()
{
    // Variables
    cashRegister counter;
    dispenserType orange(100, 50);
    dispenserType apple(100, 65);
    dispenserType mango(75, 80);
    dispenserType strawberryBanana(100, 85);
    int choice = 0;         // Variable to hold the selection

    showSelection();
    cin >> choice;

    while(choice != 9)
    {
        switch(choice)
        {
            case 1:
                sellProduct(orange, counter);
                break;
            case 2:
                sellProduct(apple, counter);
                break;
            case 3:
                sellProduct(mango, counter);
                break;
            case 4:
                sellProduct(strawberryBanana, counter);
                break;
            default:
                cout << "Invalid selection." << endl;
        }

        showSelection();
        cin >> choice;
    }

    return 0;
}

// Function Definitions
/**
 * showSelection: 
 */
void showSelection()
{
    cout << "*** Welcome to Shelly's Juice Shop ***" << endl;
    cout << "To select an item, enter " << endl;
    cout << "1 for orange juice (50 cents)" << endl;
    cout << "2 for apple juice (65 cents)" << endl;
    cout << "3 for mango juice (80 cents)" << endl;
    cout << "4 for strawberry banana juice (85 cents)" << endl;
    cout << "9 to exit" << endl;
}

void sellProduct(dispenserType& product, cashRegister& pCounter)
{
    int amount = 0;        // Variable to hold the amount entered
    int amount2 = 0;        // Variable to hold the extra amount needed

    // If the dispenser is not empty
    if(product.getNoOfItems() > 0)
    {
        cout << "Please deposit " << product.getCost() << " cents" << endl;
        cin >> amount;
        
        if(amount < product.getCost())
        {
            cout << "Please deposit another " << product.getCost() - amount << " cents" << endl;
            cin >> amount2;
            amount = amount + amount2;
        }

        if(amount >= product.getCost())
        {
            pCounter.acceptAmount(amount);
            product.makeSale();
            cout << "Collect your item at the bottom and enjoy." << endl;
        } else
            cout << "The amount is not enough. Collect what you deposited." << endl;
        
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    } else
        cout << "Sorry, this item is sold out." << endl;
}