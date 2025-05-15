// Question 28: Menu-Driven Coffee Shop
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ***Function Prototypes***
void displayBorder();
void displayMenu(int& choice, const double price[]);
void sellCoffee(int sold[]);
void displaySold(int sold[]);
void displayTotalSold(int sold[]);
void displayTotalRevenue(const double price[], int sold[]);

int main()
{
    // Variables
    const double coffeePrice[3] = {1.75, 1.90, 2.00};
    int coffeeSold[3] = {0, 0, 0};
    int choice = 0;

    // Initial Menu Display
    displayBorder();
    cout << left << setw(39) << "| Welcome to the Coffee Shop!" << "|" << endl;
    cout << left << setw(39) << "| Here's our selection:" << "|" << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "| " << left << setw(24) << "Small (9oz)" << right << setw(8) << "$" << coffeePrice[0] << " |" << endl;
    cout << "| " << left << setw(24) << "Medium (12oz)" << right << setw(8) << "$" << coffeePrice[1] << " |" << endl;
    cout << "| " << left << setw(24) << "Large (15oz)" << right << setw(8) << "$" << coffeePrice[2] << " |" << endl;

    do
    {
        displayMenu(choice, coffeePrice);
        switch(choice)
        {
            case 1: sellCoffee(coffeeSold); break;
            case 2: displaySold(coffeeSold); break;
            case 3: displayTotalSold(coffeeSold); break;
            case 4: displayTotalRevenue(coffeePrice, coffeeSold); break;
            case 5:
                displayBorder();
                cout << "| " << left << setw(37) << "Thank you for stopping by! Goodbye." << "|" << endl;
                displayBorder();
                return 0;
            default:
                displayBorder();
                cout << "| " << left << setw(37) << "Please enter a valid choice." << "|" << endl;
                continue;
        }
    } while(true);
    
    return 0;
}

// ***Functions***
void displayBorder() 
{
    cout << setfill('=') << setw(40) << "=" << endl;
    cout << setfill(' ');
}

void displayMenu(int& choice, const double price[])
{
    displayBorder();
    cout << "| " << left << setw(37) << "1: Purchase a Coffee" << "|" << endl;
    cout << "| " << left << setw(37) << "2: Show our cups of each size sold" << "|" << endl;
    cout << "| " << left << setw(37) << "3: Show the total number of cups sold" << "|" << endl;
    cout << "| " << left << setw(37) << "4: Show the total revenue made" << "|" << endl;
    cout << "| " << left << setw(37) << "5: Quit Program" << "|" << endl;
    displayBorder();
    cout << "| Enter a choice: ";
    cin >> choice;

    // Input Validation
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(40, '\n');
        choice = 0;
    }
}

void sellCoffee(int sold[])
{
    char choice = ' ';
    int noOfCups = 0;
    do
    {
        displayBorder();
        cout << "| What size coffee would you like to buy? (S/M/L): ";
        cin >> choice;
        if(cin.fail() || ((toupper(choice) != 'S') && (toupper(choice) != 'M') && (toupper(choice) != 'L')))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| " << left << setw(37) << "Please enter a valid size (S/M/L)." << "|" << endl;
            continue;
        }

        cout << "| How many cups would you like to purchase? ";
        cin >> noOfCups;
        if(cin.fail() || noOfCups <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| " << left << setw(37) << "Please enter a valid number." << "|" << endl;
            continue;
        }

        // Add sold cup amount to appropriate index
        switch(toupper(choice))
        {
            case 'S': sold[0] += noOfCups; break;
            case 'M': sold[1] += noOfCups; break;
            case 'L': sold[2] += noOfCups; break;
        }

        // Prompt for Repeat
        do
        {
            cout << "| Would you like to purchase any other cups? [y/n]: ";
            cin >> choice;
            if(cin.fail() || (tolower(choice) != 'y' && tolower(choice) != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "| " << left << setw(31) << "Please enter 'y' or 'n'." << "|" << endl;
            } else if(tolower(choice) == 'n')
                return;
            else
                break;
        } while(true);
    } while(true);
}

void displaySold(int sold[])
{
    displayBorder();
    cout << "| Small Cups Sold: " << right << setw(19) << to_string(sold[0]) + ((sold[0] == 1) ? " cup" : " cups") << " |" << endl;
    cout << "| Medium Cups Sold: " << right << setw(18) << to_string(sold[1]) + ((sold[1] == 1) ? " cup" : " cups") << " |" << endl;
    cout << "| Large Cups Sold: " << right << setw(19) << to_string(sold[2]) + ((sold[2] == 1) ? " cup" : " cups") << " |" << endl;
    displayBorder();
}

void displayTotalSold(int sold[])
{
    int sum = sold[0] + sold[1] + sold[2];
    displayBorder();
    cout << "| Total Cups Sold: " << right << setw(14) << sum << ((sum == 1) ? " cup" : " cups") << " |" << endl;
}

void displayTotalRevenue(const double price[], int sold[])
{
    double revenue = 0.0;
    for(int i = 0; i < 3; i++)
        revenue += price[i] * sold[i];

    displayBorder();
    cout << fixed << showpoint << setprecision(2);
    cout << "| Total Revenue:" << right << setw(15) << "$" << setw(7) << revenue << " |" << endl;
}