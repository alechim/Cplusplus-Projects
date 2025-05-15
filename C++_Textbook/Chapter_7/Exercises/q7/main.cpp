// Question 7: Fraction Calculator
#include <iostream>

using namespace std;

// Function Prototypes
void menu();
void promptInput(int&, bool, const string);
void addFractions(int, int, int, int, int&, int&);
void subtractFractions(int, int, int, int, int&, int&);
void multiplyFractions(int, int, int, int, int&, int&);
void divideFractions(int, int, int, int, int&, int&);
int gcd(int, int);

int main()
{
    // Run the program
    menu();

    // Exit message
    cout << "| Exiting Program... Goodbye!" << endl;
    cout << "+==============================+" << endl;
    return 0;
}

// Function Definitions
/**
 * menu: Handles the user interface of the fraction calculator. Informs the user about the 
 * program's purpose, prompts for fraction inputs, allows operation selection, performs 
 * calculations, and displays results. Controls the main program loop.
 */
void menu()
{
    // Variables
    int num1 = 0, den1 = 0;
    int num2 = 0, den2 = 0;
    int calcNum = 0, calcDen = 0;
    char choice = ' ';

    do
    {
        // Prompt for Running Program
        cout << "+==============================+" << endl;
        cout << "| Would you like to run the fraction calculator? [y/n]: ";
        cin >> choice;
        if(cin.fail() || (choice != 'y' && choice != 'n'))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "| Invalid Input! Please enter 'y' or 'n'." << endl;
            continue;
        } else if(choice == 'n')
            return;

        // Prompt for Fraction Values
        cout << "+==============================+" << endl;
        promptInput(num1, false, "Please enter the first fraction's numerator: ");
        promptInput(den1, true, "Please enter the first fraction's denominator: ");
        promptInput(num2, false, "Please enter the second fraction's numerator: ");
        promptInput(den2, true, "Please enter the second fraction's denominator: ");

        // Check for negative denominator and swap negative
        if(den1 < 0)
        {
            num1 *= -1;
            den1 *= -1;
        }
        if(den2 < 0)
        {
            num2 *= -1;
            den2 *= -1;
        }

        // Display Menu for Binary Operations
        cout << "+==============================+" << endl;
        cout << "| [+] Add Fractions            |" << endl;
        cout << "| [-] Subtract Fractions       |" << endl;
        cout << "| [*] Multiply Fractions       |" << endl;
        cout << "| [/] Divide Fractions         |" << endl;
        cout << "| [E/e] Exit Program           |" << endl;
        cout << "+==============================+" << endl;
        
        // Prompt Input
        cout << "| Please enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case '+':
                addFractions(num1, den1, num2, den2, calcNum, calcDen);
                break;
            case '-':
                subtractFractions(num1, den1, num2, den2, calcNum, calcDen);
                break;
            case '*':
                multiplyFractions(num1, den1, num2, den2, calcNum, calcDen);
                break;
            case '/':
                divideFractions(num1, den1, num2, den2, calcNum, calcDen);
                break;
            case 'E':
            case 'e':
                return;
            default:
                cin.clear();
                cin.ignore(40, '\n');
                cout << "+------------------------------+" << endl;
                cout << "| Invalid Input! Please enter a valid choice." << endl;
                cout << "+------------------------------+" << endl;
                break;
        }

        // Display Results
        cout << "+------------------------------+" << endl;
        cout << "| " << num1 << " / " << den1 << " " << choice << " " << num2 << " / " << den2 << " = " << calcNum;
        if(calcDen != 1) cout << " / " << calcDen;
        cout << endl;
    } while(true);
}

/**
 * promptInput: Collects integer input from the user with validation
 * @param int& value - Reference to the integer variable where input will be stored
 * @param bool isDen - Flag indicating if the input is a denominator (to check for zero)
 * @param const string prompt - The message displayed to the user when requesting input
 */
void promptInput(int& value, bool isDen, const string prompt)
{
    do
    {
        cout << "| " << prompt;
        cin >> value;
        if(isDen && value == 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+------------------------------+" << endl;
            cout << "| Invalid Input! The denominator cannot be 0." << endl;
            cout << "+------------------------------+" << endl;
        } else if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+------------------------------+" << endl;
            cout << "| Invalid Input! Please enter an integer value." << endl;
            cout << "+------------------------------+" << endl;
        } else
            break;
    } while(true);
}

/**
 * addFractions: Adds two fractions and simplifies the result
 * @param int num1 - Numerator of the first fraction
 * @param int den1 - Denominator of the first fraction
 * @param int num2 - Numerator of the second fraction
 * @param int den2 - Denominator of the second fraction
 * @param int& calcNum - Reference to store the resulting numerator
 * @param int& calcDen - Reference to store the resulting denominator
 */
void addFractions(int num1, int den1, int num2, int den2, int& calcNum, int& calcDen)
{
    int tempDen1 = den1;
    int tempDen2 = den2;

    if(den1 != den2)
    {
        num1 *= tempDen2;
        den1 *= tempDen2;
        num2 *= tempDen1;
        den2 *= tempDen1;
    }

    int commmonDivisor = gcd(num1 + num2, den1);

    calcNum = (num1 + num2) / commmonDivisor;
    calcDen = den1 / commmonDivisor;
}

/**
 * subtractFractions: Subtracts the second fraction from the first and simplifies the result
 * @param int num1 - Numerator of the first fraction
 * @param int den1 - Denominator of the first fraction
 * @param int num2 - Numerator of the second fraction
 * @param int den2 - Denominator of the second fraction
 * @param int& calcNum - Reference to store the resulting numerator
 * @param int& calcDen - Reference to store the resulting denominator
 */
void subtractFractions(int num1, int den1, int num2, int den2, int& calcNum, int& calcDen)
{
    int tempDen1 = den1;
    int tempDen2 = den2;

    if(den1 != den2)
    {
        num1 *= tempDen2;
        den1 *= tempDen2;
        num2 *= tempDen1;
        den2 *= tempDen1;
    }

    int commonDivisor = gcd(num1 - num2, den1);

    calcNum = (num1 - num2) / commonDivisor;
    calcDen = den1 / commonDivisor;
}

/**
 * multiplyFractions: Multiplies two fractions and simplifies the result
 * @param int num1 - Numerator of the first fraction
 * @param int den1 - Denominator of the first fraction
 * @param int num2 - Numerator of the second fraction
 * @param int den2 - Denominator of the second fraction
 * @param int& calcNum - Reference to store the resulting numerator
 * @param int& calcDen - Reference to store the resulting denominator
 */
void multiplyFractions(int num1, int den1, int num2, int den2, int& calcNum, int& calcDen)
{   
    int commonDivisor = gcd(num1 * num2, den1 * den2);

    calcNum = num1 * num2 / commonDivisor;
    calcDen = den1 * den2 / commonDivisor;
}

/**
 * divideFractions: Divides the first fraction by the second and simplifies the result
 * @param int num1 - Numerator of the first fraction
 * @param int den1 - Denominator of the first fraction
 * @param int num2 - Numerator of the second fraction
 * @param int den2 - Denominator of the second fraction
 * @param int& calcNum - Reference to store the resulting numerator
 * @param int& calcDen - Reference to store the resulting denominator
 */
void divideFractions(int num1, int den1, int num2, int den2, int& calcNum, int& calcDen)
{
    int commonDivisor = gcd(num1 * den2, den1 * num2);

    calcNum = num1 * den2 / commonDivisor;
    calcDen = den1 * num2 / commonDivisor;
}

/**
 * gcd: a recursive function to find the greatest common denominator between two integers
 * @param int a - the first integer passed
 * @param int b - the second integer passed 
 * @returns int
 */
int gcd(int a, int b)
{
    // Convert negative values
    a = abs(a);
    b = abs(b);

    // Case: gcd is found
    if(a % b == 0)
        return b;

    // Recursion
    return gcd(b, a % b);
}