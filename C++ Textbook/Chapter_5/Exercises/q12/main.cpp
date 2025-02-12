// Question 12: Population Growth of Two Towns
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int years = 0;
    int populationA = 0;
    int populationB = 0;
    double growthA = 0.0;
    double growthB = 0.0;

    // Prompt for Input
    do
    {
        cout << "Enter the population of town A and town B, where town A has less than town B: ";
        cin >> populationA >> populationB;
        if(cin.fail() || populationA <= 0 || populationB <= 0 || populationA > populationB)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 2 positive non-zero integer values where populationA < populationB." << endl;
            continue;
        }
        
        cout << "Enter the growth rate percentage of town A and town B (A must have a higher rate): ";
        cin >> growthA >> growthB;
        if(cin.fail() || growthA <= 0 || growthB <= 0 || growthA < growthB)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter 2 positive non-zero double values where growthA > growthB." << endl;
        } else
            break;
    } while(true);

    while(populationA < populationB)
    {
        populationA *= 1 + (growthA / 100);
        populationB *= 1 + (growthB / 100);
        years++;
    }

    cout << "It will take " << years << " years for town A to ";
    if(populationA == populationB)
        cout << "have the same population as town B." << endl;
    else
        cout << "have a greater population than town B." << endl;

    return 0;
}