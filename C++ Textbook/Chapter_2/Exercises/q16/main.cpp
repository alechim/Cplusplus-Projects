// Question 16: Dairy Farm
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    const double CARTON = 3.78;    // Milk carton can hold 3.78L 
    double produce = 0.38;          // Cost of producing 1L (default)
    double profit = 0.27;           // Profit of each carton sold (default)
    int milk = 0;
    int noOfCartons = 0;
    double profitMilk = 0;
    double costMilk = 0;

    // Prompt Milk Production
    while(true)
    {
        cout << "Please enter how much milk was produced today: ";
        cin >> milk;

        if(cin.fail() || milk <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero integer value." << endl;
        } else
        {
            break;
        }
    }
    // Prompt Cost of Production
    while(true)
    {
        cout << "Please enter how the cost of production is: $";
        cin >> produce;

        if(cin.fail() || produce <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero double value." << endl;
        } else
        {
            break;
        }
    }
    // Prompt Profit per Carton
    while(true)
    {
        cout << "Please enter how much profit is made per carton: $";
        cin >> profit;

        if(cin.fail() || profit <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero double value." << endl;
        } else
        {
            break;
        }
    }

    // Calculations
    noOfCartons = round(static_cast<double>(milk) / CARTON);
    costMilk = milk * produce;
    profitMilk = noOfCartons * profit;

    cout << "***************" << endl;
    cout << "* The number of cartons needed to store " << milk << "L of milk is " << noOfCartons << " cartons." << endl;
    cout << fixed << setprecision(2);
    cout << "* The cost of producing the milk is $" << costMilk << "." << endl;
    cout << "* The profit of producing the milk is $" << profitMilk << "." << endl;
    cout << "***************" << endl;

    return 0;
}