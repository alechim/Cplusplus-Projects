// Question 19: Vegetable Farming 
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// *** Functions ***
// promptInput(value, prompt)
void promptInput(double& value, const string& prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}

// promptInput(array, size, prompt)
void promptInput(double array[], int size, const string& prompt)
{
    bool isValid = false;
    do
    {
        cout << prompt;
        isValid = true;     // Assume all inputs are valid initially
        for(int i = 0; i < size; i++)
        {
            cin >> array[i];
            if(cin.fail() || array[i] <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
                isValid = false;    // Mark input as invalid
                break;              // Exit the loop and reprompt
            }
        }
    } while(!isValid);
}

// *** Main ***
int main()
{
    // Variables
    int totalFarmArea = 0;
    int noOfVegetable = 0;
    int percentOfVegetable[2];
    double seedCost[2], plantationCost[2], fertilizingCost[2], laborCost[2], vegetableSellingPrice[2];
    double totalCost = 0.0;
    double totalRevenue = 0.0;
    double profit = 0.0;
    double loss = 0.0;
    string vegName[2] = {"vegetable", "vegetables"};

    // Prompt for Input
    do
    {
        cout << "Enter the total farm area (in acres): ";
        cin >> totalFarmArea;
        if(cin.fail() || totalFarmArea <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
            continue;
        } 

        cout << "Enter the number of vegetables to be planted (1-2): ";
        cin >> noOfVegetable;
        if(cin.fail() || (noOfVegetable < 1 && noOfVegetable > 2))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value between 1-2." << endl;
        } else
            break;
    } while(true);

    switch(noOfVegetable)
    {
        case 1:
            // Prompt for Input of 1 Vegetable
            promptInput(seedCost[0], "Enter seed costs for one vegetable: $");
            promptInput(plantationCost[0], "Enter plantation costs for one vegetable: $");
            promptInput(fertilizingCost[0], "Enter fertilizing costs for one vegetable: $");
            promptInput(laborCost[0], "Enter labor costs for one vegetable: $");
            promptInput(vegetableSellingPrice[0], "Enter selling price per acre for one vegetable: $");
            
            // Calculations
            totalCost = seedCost[0] + plantationCost[0] + fertilizingCost[0] + laborCost[0];
            totalRevenue = vegetableSellingPrice[0] * totalFarmArea;
            break;
        case 2:
            // Prompt for Input of 2 Vegetables
            do
            {
                cout << "Enter the percentage of the farmland to be used for two vegetables: ";
                cin >> percentOfVegetable[0] >> percentOfVegetable[1];
                if(cin.fail() || percentOfVegetable[0] < 0 || percentOfVegetable[1] < 0 || (percentOfVegetable[0] + percentOfVegetable[1] > 100))
                {
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Invalid Input! Please enter two non-zero positive integer values that sum less than or equal to 100." << endl;
                } else
                    break;
            } while(true);
            promptInput(seedCost, 2, "Enter seed costs for two vegetables: $");
            promptInput(plantationCost, 2, "Enter plantation costs for two vegetables: $");
            promptInput(fertilizingCost, 2, "Enter fertilizing costs for two vegetables: $");
            promptInput(laborCost, 2, "Enter labor costs for two vegetables: $");
            promptInput(vegetableSellingPrice, 2, "Enter selling prices per acre for two vegetables: $");

            // Calculations
            percentOfVegetable[0] /= 100;
            percentOfVegetable[1] /= 100;
            totalCost = seedCost[0] + seedCost[1] + plantationCost[0] + plantationCost[1] + fertilizingCost[0] + fertilizingCost[1] + laborCost[0] + laborCost[1];
            totalRevenue = (vegetableSellingPrice[0] * totalFarmArea * percentOfVegetable[0]) + (vegetableSellingPrice[1] * totalFarmArea * percentOfVegetable[1]);
            break;
        default:
            break;
    }

    // Display Results
    cout << fixed << showpoint << setprecision(2);
    cout << "The total revenue of " << noOfVegetable << " " << vegName[noOfVegetable - 1] << " is $" << totalRevenue << endl;
    if(totalRevenue - totalCost < 0)
        cout << "Loss: -$" << -(totalRevenue - totalCost) << endl;
    else    
        cout << "Profit: $" << totalRevenue - totalCost << endl;

    return 0;
}