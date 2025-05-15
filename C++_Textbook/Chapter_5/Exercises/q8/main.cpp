// Question 8: Integer Manipulation
/**
 * Q8) Use While Loop
 * Q9) Use For Loop
 * Q10) Use do...while Loop
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    int firstNum = 0;
    int secondNum = 0;
    int sum = 0;
    
    // a) Prompt for Input of both integers, firstNum > secondNum
    // Q8) while(true)
    // Q9) for(int i = 0; true; i++)
    do
    {
        cout << "Enter two integer values, the first number must be less than the second number: ";
        cin >> firstNum >> secondNum;
        if(cin.fail() || firstNum >= secondNum)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two integer values where the first number is less than the second number." << endl;
        } else
            break;
    } while(true);
    
    // b) Output all odd numbers between firstNum and secondNum
    // c) Output the sum of all even numbers between firstNum and secondNum
    // Q8) int counter = firstNum; while(counter <= secondNum){... counter++;}
    // Q10) int counter = firstNum; do{... counter++;} while(counter < secondNum)
    cout << "\nThe odd numbers between " << firstNum << " and " << secondNum << " is:" << endl;
    for(int i = firstNum; i <= secondNum; i++)
    {   
        // Determine Evens and Odds
        switch(i % 2)
        {
            case 0:
                sum += i;
                break;
            case 1:
            case -1:
                cout << i << " ";
                break;
        }
    } 
    cout << "\n\nThe sum of all even numbers between " << firstNum << " and " << secondNum << " is " << sum << "." << endl;

    // d) Output the numbers and their squares between 1 and 10.
    if(secondNum >= 1)
    {   
        cout << "\nThe squares between " << firstNum << " and " << secondNum << " with a minimum of 1 and maximum of 10 is: " << endl;
        // Find lower and upper bounds
        // Q9) for(int i = ((firstNum < 1) ? 1 : firstNum); i < ((secondNum > 10) ? 10 : secondNum); i++){...}
        // Q10) lower = ..., upper = ...; do {...} while(lower < upper)
        int lower = (firstNum < 1) ? 1 : firstNum;
        int upper = (secondNum > 10) ? 10 : secondNum;
        while(lower <= upper)
        {
            cout << right << setw(2) << lower << " - " << left << setw(2) << lower * lower << endl;
            lower++;
        }
    }

    return 0;
}