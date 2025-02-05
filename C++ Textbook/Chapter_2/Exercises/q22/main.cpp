// Question 22: Number of Bags to Store Rice
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    // 1 Metric Ton = 2,205 lbs
    int tonToPounds = 2205;
    int pounds = 0;
    int bags = 0;

    while(true)
    {
        cout << "Please enter how many pounds of rice can be held in one bag: ";
        cin >> pounds;

        if(cin.fail() || pounds < 0 || pounds != static_cast<int>(pounds))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer." << endl;
        } else
        {
            bags = static_cast<int>(ceil(static_cast<double>(tonToPounds) / pounds));
            break;
        }
    }

    cout << "The number of bags needed to hold a metric ton of rice is " << bags << " bags with " << pounds << " lbs per bag." << endl;

    return 0;
}