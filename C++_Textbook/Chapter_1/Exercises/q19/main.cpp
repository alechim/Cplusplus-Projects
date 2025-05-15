// Question 19: Online Shipping
#include <iostream>

using namespace std;

int main()
{
    // Variables
    double cost = 0.0;
    double totalCost = 0.0;
    int noOfItems = 0;

    while(true)
    {
        cout << "How many items would you like to order? ";
        cin >> noOfItems;

        if(cin.fail() || noOfItems < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer." << endl;
        } else
        {
            break;
        }
    }

    for(int i = 0; i < noOfItems; i++)
    {
        while(true)
        {
            cout << "Please enter the price of item " << i + 1 << ": $";
            cin >> cost;

            if(cin.fail() || cost < 0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a positive double." << endl;
            } else
            {
                break;
            }
        }
        totalCost += cost;
    }

    // totalCost >= 200 -> Free Shipping
    if(totalCost < 200.00)
    {
        // Shipping and Handling: $10 per Item
        totalCost += (10 * noOfItems);
    }

    cout << "The total cost of your order is $" << totalCost << "." << endl;

    return 0;
}