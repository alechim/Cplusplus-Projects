// Question 22: Refactored Example 10-9
// - Added 3 different simulations using the die specification and implementation files
#include <iostream>
#include <fstream>
#include "die.h"

using namespace std;

// Function Prototypes
void promptInput(string&, string);
void promptInput(int&, int, string);
void promptInput(int&, string);

void promptRoll(die);
void simulateDie(die, int);
void testRolls(die, int, int[], int[][3]);
void displayResults(ofstream&, int, int, int[][3]);
void barGraph(die);
int sumDice(die, int);

int main()
{
    die dice;
    
    // Run the first simulation (Prompt User for rolls)
    promptRoll(dice);

    // Run the second simulation (Test run of incrementing runs for desired sums)
    cout << "==========" << endl;
    simulateDie(dice, 10'000);
    cout << "----------" << endl;
    simulateDie(dice, 100'000);
    cout << "----------" << endl;
    simulateDie(dice, 1'000'000);
    cout << "----------" << endl;
    simulateDie(dice, 10'000'000);
    cout << "----------" << endl;
    simulateDie(dice, 100'000'000);
    cout << "==========" << endl;

    // Run the third simulation (Generate a bar graph)
    barGraph(dice);

    return 0;
}

/**
 * promptInput: Gets and validates a string value from the user
 * @param string& value - Reference to the string variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(string& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a valid string value." << endl;
        } else
            break;
    } while(true);
}

/**
 * promptInput: Gets and validates an integer value from the user (meant for die with a lower and upper bounds)
 * @param int& value - Reference to the integer variable to store the input
 * @param int bounds - The value which will specify both the lower and upper bounds for the die
 * @param string prompt - Message to display to the user
 */
void promptInput(int& value, int bounds, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < bounds || value > 6 * bounds)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value from " << bounds << " to " << 6 * bounds << "." << endl;
        } else
            break;
    } while(true);
}

/**
 * promptInput: Gets and validates an integer value from the user
 * @param int& value - Reference to the integer variable to store the input
 * @param string prompt - Message to display to the user
 */
void promptInput(int& value, string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive non-zero integer value." << endl;
        } else
            break;
    } while(true);
}

/**
 * promptRoll: Prompts the user on the target sum and the times the die will be rolled and outputs the results
 * @param die dice - The dice object to be used
 */
void promptRoll(die dice)
{
    // Variables
    int noOfRolls = 0, target = 0, count = 0;

    // Prompt for targetSum and noOfRolls
    promptInput(target, 10, "Enter the target sum value (10 - 60): ");
    promptInput(noOfRolls, "Enter the number of times to roll the die: ");
    
    // Loop the times the die will be rolled and increments if targetSum is the same as the specified target
    for(int i = 0; i < noOfRolls; i++)
        if(sumDice(dice, 10) == target)
            count++;
    
    cout << "After " << noOfRolls << " rolls, the target sum " << target << " was found " << count << " times." << endl;
}

/**
 * simulateDie: A function for the purpose of rolling the die x times and finding the specified target sums
 * @param die dice - The dice object to be used
 * @param int noOfRolls - The number of rolls to be looped
 */
void simulateDie(die dice, int noOfRolls)
{
    // 0: 10, 1: 25, 2: 40, 3: 60
    int count[4] = {0, 0, 0, 0};
    for(int i = 0; i < noOfRolls; i++)
    {
        switch(sumDice(dice, 10))
        {
            case 10:
                count[0]++;
                break;
            case 25:
                count[1]++;
                break;
            case 40:
                count[2]++;
                break;
            case 60:
                count[3]++;
                break;
            default:
                break;
        }
    }

    // Display Results
    cout << "After " << noOfRolls << ", the target sums were found: " << endl;
    cout << "10: " << count[0] << " times" << endl;
    cout << "25: " << count[1] << " times" << endl;
    cout << "40: " << count[2] << " times" << endl;
    cout << "60: " << count[3] << " times" << endl;
}

/**
 * testRolls: A lower order function used in barGraph that contains the code to run the simulations
 * @param die dice - The dice object to be used
 * @param int rolls - The number of rolls meant to be thrown
 * @param int target[] - The array containing the targetSums for all dies
 * @param int count[][3] - The 2D array to store the incremented counter values
 */
void testRolls(die dice, int rolls, int target[], int count[][3])
{
    // Setup for the row index
    int row = 0;
    if(rolls == 3000)
        row = 1;
    else if(rolls == 5000)
        row = 2;

    for(int i = 0; i < rolls; i++)
    {
        if(target[0] == sumDice(dice, 4))
            count[row][0]++;
        if(target[1] == sumDice(dice, 5))
            count[row][1]++;
        if(target[2] == sumDice(dice, 6))
            count[row][2]++;
    }
}

/**
 * displayResults: A lower order function used in barGraph that formats and creates the bar graph for the output file
 * @param ofstream& oFile - The file to be outputted to
 * @param int target - The target sum
 * @param int diceNo - The number of die that were thrown (4, 5 or 6)
 * @param int count[][3] - The 2D array containing the counter values to be used for the bar graph
 */
void displayResults(ofstream& oFile, int target, int diceNo, int count[][3])
{
    oFile << "=========================" << endl;
    oFile << "| Target Sum: " << target << "        |" << endl;
    oFile << "===== " << diceNo << " dice thrown =====" << endl;
    oFile << "2500 rolls - ";
    for(int i = 0; i < count[0][diceNo - 4]; i++)
        oFile << "*";

    oFile << endl << "3000 rolls - ";
    for(int i = 0; i < count[1][diceNo - 4]; i++)
        oFile << "X";
    
    oFile << endl << "5000 rolls - ";
    for(int i = 0; i < count[2][diceNo - 4]; i++)
        oFile << "#";
    oFile << endl;
}

/**
 * barGraph: Runs three simulations of 2500, 3000, and 5000 rolls on 3 target sums with 4, 5, and 6 die, then generates a bar graph
 * @param die dice - The dice object to be used
 */
void barGraph(die dice)
{
    // Variables
    ofstream oFile;
    string fileName = "";
    int target[3] = {0, 0, 0};

    // Prompt targetSums for 4, 5, and 6 die
    promptInput(target[0], 4, "Enter the first target sum value (4 - 24): ");
    promptInput(target[1], 5, "Enter the second target sum value (5 - 30): ");
    promptInput(target[2], 6, "Enter the third target sum value (6 - 36): ");
    cout << "----------" << endl;

    // 0: 2500 rolls, 1: 3000 rolls, 2: 5000 rolls
    // 0: 4 die, 1: 5 die, 2: 6 die
    int count[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
    // Prompt for fileName and open it
    promptInput(fileName, "Enter the output file name: ");
    oFile.open(fileName);

    // Run the simulation of 2500, 3000, and 5000 rolls
    testRolls(dice, 2500, target, count);
    testRolls(dice, 3000, target, count);
    testRolls(dice, 5000, target, count);

    // Generate the barGraph and diplay the results
    displayResults(oFile, target[0], 4, count);
    oFile << endl;
    displayResults(oFile, target[1], 5, count);
    oFile << endl;
    displayResults(oFile, target[2], 6, count);

    // Close the file
    oFile.close();
}

/**
 * sumDice: Rolls some amount of die and sums the values together
 * @param die dice - The dice class object
 * @param int rolls - The number of dice being rolled
 * @return int - The sum of the rolls 
 */
int sumDice(die dice, int rolls)
{
    int sum = 0;

    for(int i = 0; i < rolls; i++)
    {
        dice.roll();
        sum += dice.getNum();
    }
    
    return sum;
}