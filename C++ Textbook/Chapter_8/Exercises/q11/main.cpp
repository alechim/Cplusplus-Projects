// Question 11: Adding Large Integers
/**
 * Hint: Read numbers as strings and store the digits of the number in the reverse order
 */
#include <iostream>
#include <cstring>

using namespace std;

// Function Prototypes
void promptInput(char[], int&);
void reverseOrder(char[], int);

int main()
{
    char num1[21], originalNum1[21];
    char num2[21], originalNum2[21];
    char results[22];
    int maxLimit = 0;
    int limit1 = 20;
    int limit2 = 20;
    int carry = 0;
    int sum = 0;

    // Prompt for Input for both c-strings
    promptInput(num1, limit1);
    promptInput(num2, limit2);

    // Store original values of input for final display
    strcpy(originalNum1, num1);
    strcpy(originalNum2, num2);

    // Reverse the order of the c-string for simpler long addition
    reverseOrder(num1, limit1);
    reverseOrder(num2, limit2);

    // Determine max limit
    maxLimit = (limit1 < limit2) ? limit1 : limit2;

    // Loop to perform addition
    for(int i = 0; i < maxLimit; i++)
    {
        int digit1 = (i < limit1) ? (num1[i] - '0') : 0;
        int digit2 = (i < limit2) ? (num2[i] - '0') : 0;

        // Perform Addition
        sum = carry + digit1 + digit2;

        // Store result and update carry
        results[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    // Handle final carry if exists
    if(carry > 0) {
        results[maxLimit] = carry + '0';
        maxLimit++;             // Increase the result length
    }

    // Add null terminator
    results[maxLimit] = '\0';

    // Reverse the Results
    reverseOrder(results, maxLimit);

    // Determine if overflow exists
    if(maxLimit > 20)
        cout << "This addition leads to an overflow..." << endl;
    cout << "The results of " << originalNum1 << " + " << originalNum2 << " = " << results << endl;

    return 0;
}

// Function Definitions
/**
 * promptInput: Prompts and validates the user's input for the 20-character c-string
 * @param char number[] - The c-string to be updated
 * @param int& limit - The amount of elements within the c-string
 */
void promptInput(char number[], int& limit)
{
    do
    {
        bool invalidValue = false;
        cout << "Please enter a value of maximum 20 digits: ";
        cin.getline(number, 21);

        // Get the actual length of the string entered
        limit = strlen(number);
        
        // Check if length exceeds 20
        if(limit > 20)
            invalidValue = true;
        else
        {
            // Verify all characters are digits
            for(int i = 0; i < limit; i++)
            {
                if(number[i] < '0' || number[i] > '9')
                {
                    invalidValue = true;
                    break;
                }
            }
        }

        // Validate Input is accepted
        if(cin.fail() || invalidValue)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value of maximum 20 digits." << endl;
        } else
            break;
    } while(true);
}

/**
 * reverseOrder: Reverses the order of a c-string to be used in long integer addition
 * @param char number[] - The c-string to be reversed
 * @param int limit - The limit to reverse the correct amount of digits within the c-string
 */
void reverseOrder(char number[], int limit)
{
    // Create a temporary array and store values
    char temp[21];
    for(int i = 0; i < limit; i++)
        temp[i] = number[i];
    temp[limit] = '\0';            // Null Terminator

    // Reverse order of array
    for(int i = 0; i < limit; i++)
        number[i] = temp[limit - 1 - i];
}