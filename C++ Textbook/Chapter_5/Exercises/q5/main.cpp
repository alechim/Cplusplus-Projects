// Question 5: Multiples of 3 and 5
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int num1 = 0;
    int num2 = 0;
    int threes = 0;
    int fives = 0;

    // Prompt for Input
    do
    {
        cout << "Enter two different integers (lower first, upper second). 'num1' must be less than 'num2': ";
        cin >> num1 >> num2;
        if(cin.fail() || num1 >= num2)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two different integer values." << endl;
            cout << "Usage Case: 'num1' 'num2' (num1 < num2)" << endl;
        } else
            break;
    } while(true);

    // Find the first multiple of 3 within the range
    int firstMultipleOf3 = num1;
    if (num1 % 3 != 0) 
        firstMultipleOf3 = num1 + (3 - (num1 % 3)); 
    for (int i = firstMultipleOf3; i <= num2; i += 3)
        threes++;

    // Find the first multiple of 5 within the range
    int firstMultipleOf5 = num1;
    if (num1 % 5 != 0) 
        firstMultipleOf5 = num1 + (5 - (num1 % 5)); 
    for (int i = firstMultipleOf5; i <= num2; i += 5)
        fives++;

    // Display Results
    cout << endl;
    if(threes > 0)
        cout << "There are " << threes << " values between " << num1 << " and " << num2 << " that are divisible by 3." << endl;
    else
        cout << "No numbers between " << num1 << " and " << num2 << " are divisible by 3." << endl;
    if(fives > 0)
        cout << "There are " << fives << " values between " << num1 << " and " << num2 << " that are divisible by 5." << endl;
    else
        cout << "No numbers between " << num1 << " and " << num2 << " are divisible by 5." << endl;


    return 0;
}