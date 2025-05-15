// Question 17: House Price Per Area Models
/**
 * Given:
 * - Three Models
 *   > Colonial
 *   > Split-Entry
 *   > Single-Story
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double basePrice = 0.0;
    double finishedArea[3];
    double totalPrice[3];

    // Prompt for Input
    do
    {
        cout << "Enter the base price of the model houses: ";
        cin >> basePrice;
        if(cin.fail() || basePrice <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        }

        cout << "Enter the finished area size of the Colonial, Split-Entry and Single-Story models in square feet: ";
        cin >> finishedArea[0] >> finishedArea[1] >> finishedArea[2];
        if(cin.fail() || finishedArea[0] <= 0.0 || finishedArea[1] <= 0.0 || finishedArea[2] <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 3 non-zero positive double values." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    for(int i = 0; i < 3; i++)
        totalPrice[i] = basePrice / finishedArea[i];
    
    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The price per square foot of the Colonial model is $" << totalPrice[0] << "." << endl;
    cout << "The price per square foot of the Split-Entry model is $" << totalPrice[1] << "." << endl;
    cout << "The price per square foot of the Single-Story model is $" << totalPrice[2] << "." << endl;
    cout << "The cheapest option is the ";
    if(totalPrice[0] <= totalPrice[1] && totalPrice[0] <= totalPrice[2])
        cout << "Colonial model." << endl;
    else if(totalPrice[1] <= totalPrice[0] && totalPrice[1] <= totalPrice[2])
        cout << "Split-Entry model." << endl;
    else if(totalPrice[2] <= totalPrice[0] && totalPrice[2] <= totalPrice[1])
        cout << "Single-Story model." << endl;

    return 0;
}