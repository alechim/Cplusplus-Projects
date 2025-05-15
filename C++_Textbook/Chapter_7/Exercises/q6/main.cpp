// Question 6: Random Number Operations
/**
 * Operations:
 * - Double the number
 * - Reverse the digits of the number
 * - Raise the number to the power of 2, 3, or 4
 * - Sum the digits of the number
 * - If double digit, raise the first digit to the power of the second digit
 * - If triple digit and if the last digit is <= 4, raise the first two digits to the power of the last digit
 * After Operations:
 * - If the number is less than 10, add 10 to the number
 * - Determine if number is prime
 * - Each operation's return value is sent to the next operation
 */
#include <iostream>
#include <cmath>

using namespace std;

// Function Prototypes
bool isPrime(int);
void doubleValue(int&);
void reverseDigits(int&);
void selectPower(int&);
void sumDigits(int&);
void raisePower(int&);

int main()
{
    // Variables
    bool exitProgram = false;
    char choice = ' ';

    // Seed and Generate Random 2 Digit Value
    srand(time(0));
    int value = rand() % 99;

    do
    {
        // If value < 10, add 10
        if(value < 10)
        {
            cout << "| Adding 10 to the value \'" << value << "\'" << endl;
            value += 10;
        }

        // Display Menu
        cout << "+================================================+" << endl;
        cout << "| The current number is \'" << value << "\'" << endl; 
        cout << "+------------------------------------------------+" << endl;
        cout << "| [1] Double the number                          |" << endl;
        cout << "| [2] Reverse the digits of the number           |" << endl;
        cout << "| [3] Raise the number by a power of 2, 3, or 4  |" << endl;
        cout << "| [4] Sum of the digits of the number            |" << endl;
        cout << "| [5] Raise the number based on current digits   |" << endl;
        cout << "| [E/e] Exit Program                             |" << endl;
        cout << "+================================================+" << endl;

        // Prompt Input
        cout << "| Please enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case '1':
                doubleValue(value);
                break;
            case '2':
                reverseDigits(value);
                break;
            case '3':
                selectPower(value);
                break;
            case '4':
                sumDigits(value);
                break;
            case '5':
                raisePower(value);
                break;
            case 'E':
            case 'e':
                exitProgram = true;
                break;
            default:
                cout << "+------------------------------------------------+" << endl;
                cout << "| Invalid Choice! Please enter a valid option.   |" << endl;
                break;
        }
    } while(!exitProgram);

    cout << "+================================================+" << endl;
    cout << "| The final number created is \'" << value << "\'" << endl; 
    cout << "| Exiting Program... Goodbye!" << endl;
    cout << "+================================================+" << endl;
    return 0;
}

// Function Definitions
/**
 * isPrime: determines whether the passed value is a prime number or not
 * @param int value - the passed integer value
 * @return bool - returns whether the integer is prime or not
 */
bool isPrime(int value)
{
    if (value == 0 || value == 1 || value % 2 == 0) 
        return false; 
    else if(value == 2)
        return true;
    else
        for(int i = 3; i <= static_cast<int>(sqrt(value)); i += 2)
            if(value % i == 0)
                return false;
    return true;
}

/**
 * doubleValue: doubles the passed integer value
 * @param int value - the passed integer value
 */
void doubleValue(int& value)
{
    value *= 2;
}

/**
 * reverseDigits: finds each individual digit of the passed integer value and reverses their order
 * @param int value - the passed integer value
 */
void reverseDigits(int& value)
{
    int temp = value;
    value = 0;
    while(temp > 0)
    {
        value = value * 10 + temp % 10;
        temp /= 10;
    }
}

/**
 * selectPower: prompts the user to raise the passed integer value by 2, 3, or 4
 * @param int value - the passed integer value
 */
void selectPower(int& value)
{
    int raise = 0;
    do
    {
        cout << "| Select the power you would like to raise the number by (2/3/4): ";
        cin >> raise;
        if(cin.fail() || (raise < 2 && raise > 4))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "+------------------------------------------------+" << endl;
            cout << "| Invalid Input! Please enter '2', '3', or '4'." << endl;
        } else
            break;
    } while(true);
    value = pow(value, raise);
}

/**
 * sumDigits: sums all of the digits in the passed integer value
 * @param int value - the passed integer value
 */
void sumDigits(int& value)
{
    int temp = value;
    value = 0;
    while(temp > 0)
    {
        value += temp % 10;
        temp /= 10;
    }
}

/**
 * raisePower: runs the function based on stated conditions
 * > If double digit, raise the first digit to the power of the second digit
 * > If triple digit and if the last digit is <= 4, raise the first two digits to the power of the last digit
 * @param int value - the passed integer value
 */
void raisePower(int& value)
{
    int raise = 0;
    if(value < 100)
    {
        raise = value % 10;
        value /= 10;
        value = pow(value, raise);
        return;
    } else 
    {
        if(value % 10 <= 4)
        {
            value = pow(((value - (value % 10)) / 10), value % 10);
            return;
        }
    }
    cout << "This operation cannot be performed on \'" << value << "\' because it is neither a 2-digit or 3-digit number." << endl;
}