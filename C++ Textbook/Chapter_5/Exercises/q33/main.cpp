// Question 33: Preparing Cooking Times
#include <iostream>

using namespace std;

// *** Functions ***
// promptInput(value, prompt)
void promptInput(int& value, const string& prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}

int main()
{
    // Variables
    int initialTime = 0;
    int followingTime = 0;
    int totalTime = 0;
    int noOfDishes = 0;
    int sumTime = 0;

    // Prompt for Input
    promptInput(initialTime, "Please enter the time it takes to prepare the first dish (minutes): ");
    promptInput(followingTime, "Please enter the time it takes to prepare following dishes (minutes): ");
    promptInput(totalTime, "Please enter the total time needed to prepare all the dishes (minutes): ");

    // Calculations
    for(sumTime = initialTime; sumTime <= totalTime; sumTime += initialTime + (followingTime * noOfDishes))
    {
        cout << initialTime + (followingTime * noOfDishes);
        noOfDishes++;
        cout << ((sumTime + initialTime + (followingTime * noOfDishes)) <= totalTime ? " + " : " = " + to_string(sumTime));
    }
    cout << endl;
    cout << "The cook can prepare " << noOfDishes << (noOfDishes == 1 ? " dish " : " dishes ") << "in " << totalTime << " minutes." << endl;

    return 0;
}