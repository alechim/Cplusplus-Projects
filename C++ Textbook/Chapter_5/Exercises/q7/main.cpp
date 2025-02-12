// Question 7: Determine Divisibility by 11
/**
 * Given:
 * - Let n = a_k * a_k-1 * a_k-2 * ... * a_1 * a_0
 * - t = a_0 - a_1 + a_2 - ... +  (-1)^k * a_k
 */
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int n = 0;
    int t = 0;
    int tmp = 0;

    // Prompt for Input
    do
    {
        cout << "Enter an integer value: ";
        cin >> n;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while(true);
    
    // Handle Negative
    tmp = abs(n);
    cout << "t = ";
    
    // Extract first digit separately to handle formatting
    t = tmp % 10;  
    cout << t;  
    tmp /= 10;

    // Process remaining digits, alternating between + and -
    bool isAddition = false;  
    while (tmp > 0) 
    {
        int digit = tmp % 10;
        cout << (isAddition ? " + " : " - ") << digit;
        t = isAddition ? t + digit : t - digit;
        
        isAddition = !isAddition;  // Flip between + and -
        tmp /= 10;
    }
    
    cout << " = " << t << endl << endl;
    if(t % 11 == 0)
        cout << "The number " << n << " is divisible by 11." << endl;
    else
        cout << "The number " << n << " is not divisible by 11." << endl;

    return 0;
}