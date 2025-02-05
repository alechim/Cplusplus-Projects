// Question 16: Author Royalties
/**
 * Given:
 * - Three Options
 *   > 5k upon delivery, 20k when published
 *   > 12.5% net price per novel sold
 *   > 10% net price for first 4k copies sold, 14% net price after 4k copies sold
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Constant Variables
    const double DELIVERY_PAYMENT = 5000;
    const double PUBLICATION_PAYMENT = 20000;
    const double FIXED_RATE = 0.125;
    const double INITIAL_ROYALTY = 0.10;
    const double FINAL_ROYALTY = 0.14;
    // Variables
    double netPrice = 0.0;
    int estimatedCopiesSold = 0;
    double options[3];

    // Prompt for Input
    do
    {
        cout << "Enter the net price of each copy of the novel: $";
        cin >> netPrice;
        if(cin.fail() || netPrice <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        }

        cout << "Enter the estimated number of copies that will be sold: ";
        cin >> estimatedCopiesSold;
        if(cin.fail() || estimatedCopiesSold <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;
    } while(true);
    
    // Calculations
    options[0] = DELIVERY_PAYMENT + PUBLICATION_PAYMENT;
    options[1] = (FIXED_RATE * netPrice) * estimatedCopiesSold;
    // - Option 3: 10% - first 4k, 14% - after 4k
    if(estimatedCopiesSold > 4000)
    {
        options[2] = (INITIAL_ROYALTY * netPrice * 4000) + (FINAL_ROYALTY * netPrice * (estimatedCopiesSold - 4000));
    } else 
        options[2] = (INITIAL_ROYALTY * netPrice) * estimatedCopiesSold;

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "=====" << endl;
    cout << "The first option will have a profit of $" << options[0] << endl;
    cout << "The second option will have a profit of $" << options[1] << endl;
    cout << "The third option will have a profit of $" << options[2] << endl;
    cout << "=====" << endl;
    cout << "The best option to choose is the ";
    if(options[0] > options[1] && options[0] > options[2])
        cout << "first with a profit of $" << options[0] << endl;
    else if(options[1] > options[0] && options[1] > options[2])
        cout << "second with a profit of $" << options[1] << endl;
    else if(options[2] > options[0] && options[2] > options[1])
        cout << "third with a profit of $" << options[2] << endl;

    return 0;
}