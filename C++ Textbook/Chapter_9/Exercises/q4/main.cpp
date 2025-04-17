// Question 4: Automatic Breakfast Billing System
#include <iostream>
#include <iomanip>

using namespace std;

// Structs
struct menuItemType
{
    string menuItem;
    double menuPrice;
};

// Function Prototypes
void getData(menuItemType[]);
void showMenu(menuItemType[]);
void printCheck(menuItemType[], int[]);

int main()
{
    menuItemType menuList[8];
    int order[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    char choice = ' ';
    int select = 0;

    getData(menuList);
    showMenu(menuList);

    do
    {
        cout << "| What would you like to order?: ";
        cin >> select;
        if(cin.fail() || select < 1 || select > 8)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter one of the valid menu items." << endl;
        } else
            break;
    } while(true);

    do 
    {
        order[select - 1]++;
        select = 0;

        cout << "| Would you like to order more? [y/n]: ";
        cin >> choice;
        if(cin.fail() || (choice != 'y' && choice != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter one of the valid menu items." << endl;
            continue;
        }

        if(choice == 'n')
            break;

        do
        {
            cout << "| What would you like to order?: ";
            cin >> select;
            if(cin.fail() || select < 1 || select > 8)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter one of the valid menu items." << endl;
            } else
                break;
        } while(true);
    } while(true);
    cout << "+" << setw(32) << setfill('=') << "" << "+" << endl << setfill(' ');
    printCheck(menuList, order);

    return 0;
}

// Function Definitions
/**
 * getData:
 * @param menuItemType menu[] - 
 */
void getData(menuItemType menu[])
{
    string item[8] = {"Plain Egg", "Bacon and Egg", "Muffin", "French Toast", "Fruit Basket", "Cereal", "Coffee", "Tea"};
    double price[8] = {1.45, 2.45, 0.99, 1.99, 2.49, 0.69, 0.50, 0.75};

    for(int i = 0; i < 8; i++)
    {
        menu[i].menuItem = item[i];
        menu[i].menuPrice = price[i];
    }
}

/**
 * showMenu:
 * @param menuItemType menu[] - 
 */
void showMenu(menuItemType menu[])
{
    cout << "+" << setw(32) << setfill('=') << "" << "+" << endl << setfill(' ');
    cout << "| Welcome to Johnny's Restaurant |" << endl;
    cout << "+" << setw(32) << setfill('-') << "" << "+" << endl << setfill(' ');
    cout << fixed << showpoint << setprecision(2);
    for(int i = 0; i < 8; i++)
        cout << "| " << i + 1 << ". " << left << setw(22) << menu[i].menuItem << "$" << menu[i].menuPrice << " |" << endl;
    cout << "+" << setw(32) << setfill('=') << "" << "+" << endl << setfill(' ');
}

/**
 * printCheck: 
 * @param menuItemType menu[] - 
 * @param int orders[] - 
 */
void printCheck(menuItemType menu[], int orders[])
{
    double sum = 0.0;
    double tax = 0.05;      // 5% tax
    cout << "| Welcome to Johnny's Restaurant |" << endl;
    cout << "+" << setw(32) << setfill('-') << "" << "+" << endl << setfill(' ');
    for(int i = 0; i < 8; i++)
    {
        if(orders[i] != 0)
        {
            cout << "| " << left << setw(4) << orders[i] << setw(21) << menu[i].menuItem << "$" << menu[i].menuPrice * orders[i] << " |" << endl; 
            sum += menu[i].menuPrice * orders[i];
        }
    }
    tax = sum * tax;
    cout << "| " << left << setw(4) << "" << "Tax" << setw(18) << "" << "$" << tax << " |" << endl;
    cout << "| " << left << setw(4) << "" << "Amount Due" << setw(11) << "" << "$" << sum + tax << " |" << endl;
    cout << "+" << setw(32) << setfill('=') << "" << "+" << endl << setfill(' ');
}