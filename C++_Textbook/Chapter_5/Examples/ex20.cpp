// Example 5-20: Divisibility Test by 3 and 9
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int num = 0;
    int temp = 0;
    int sum = 0;
    
    cout << "Enter a positive integer: ";
    cin >> num;
    cout << endl;

    temp = num;

    do
    {
        sum = sum + num % 10;   // Extract the last digit and add it to the sum
        num = num / 10;         // Remove the last digit
    } while(num > 0);
    
    cout << "The sum of the digits = " << sum << endl;

    if(sum % 9 == 0)
        cout << temp << " is divisible by 3 and 9." << endl;
    else if(sum % 3 == 0)
        cout << temp << " is divisible by 3, but not 9." << endl;
    else
        cout << temp << " is not divisible by 3 or 9." << endl;

    return 0;
}