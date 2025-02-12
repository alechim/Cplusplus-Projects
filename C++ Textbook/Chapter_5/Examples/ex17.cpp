// Example 5-17: Sum of first n positive integers
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int counter = 0;    // Loop control variable
    int sum = 0;        // Variable to store the sum of numbers
    int N = 0;          // Variable to store the number of first positive integers to be added

    cout << "Line 8: Enter the number of positive integers to be added: ";
    cin >> N;
    cout << endl;

    for(counter = 1; counter <= N; counter++)
        sum = sum + counter;

    cout << "Line 14: The sum of the first " << N << " positive integers is " << sum << endl;

    return 0;
}