// Question 20: Cost of Hotel Room Renting
/**
 * Given (Conditions):
 * - Number of Rooms 
 *   > At least 10 -> 10% discount
 *   > At least 20 -> 20% discount
 *   > At least 30 -> 30% discount
 * - Booked at least 3 days -> Additional 5% discount
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double costRent = 0;
    int noOfRooms = 0;
    int noOfDays = 0;
    double salesTax = 0.0;
    double discount = 0.0;
    double totalBill = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the cost of renting one room: $";
        cin >> costRent;
        if(cin.fail() || costRent <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Enter the number of rooms to book: ";
        cin >> noOfRooms;
        if(cin.fail() || noOfRooms <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Enter the number of days the rooms are booked: ";
        cin >> noOfDays;
        if(cin.fail() || noOfDays <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        }

        cout << "Enter the sales tax percentage (%): ";
        cin >> salesTax;
        if(cin.fail() || salesTax <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);

    // Calculations
    if(noOfRooms >= 30)
        discount = 0.30;
    else if(noOfRooms >= 20)
        discount = 0.20;
    else if(noOfRooms >= 10)
        discount = 0.10;
    
    double roomDiscountedPrice = costRent * (1 - discount);

    // Additional 5% discount for bookings of at least 3 days
    if(noOfDays >= 3)
        roomDiscountedPrice *= 0.95; // Apply 5% discount separately

    double totalRoomCost = roomDiscountedPrice * noOfRooms * noOfDays;

    // Apply sales tax
    double taxAmount = totalRoomCost * (salesTax / 100);
    totalBill = totalRoomCost + taxAmount;

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "=====" << endl;
    cout << "The cost of renting one room is $" << costRent << endl;
    cout << "The discounted price of each room is: $" << roomDiscountedPrice << endl;
    cout << "Number of Rooms booked: " << noOfRooms << endl;
    cout << "Number of Days booked: " << noOfDays << endl;
    cout << "Total Cost of Rooms: $" << totalRoomCost << endl; 
    cout << "Sales Tax: $" << taxAmount << endl;
    cout << "Total Bill: $" << totalBill << endl;
    cout << "=====" << endl;

    return 0;
}