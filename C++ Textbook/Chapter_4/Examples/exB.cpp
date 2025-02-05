// Example 4-B: Comparing Numbers and Output Largest
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int num1 = 0;
    int num2 = 0;

    do
    {
        cout << "Enter any two integers: ";
        cin >> num1 >> num2;
        cout << endl;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter two integer values." << endl;
            cout << "Use Case: 'int1' 'int2'" << endl;
            continue;
        } else
        {
            break;
        }
    } while (true);
    
    cout << "The two integers entered are " << num1 << " and " << num2 << endl;

    if(num1 > num2)
        cout << "The larger number is " << num1 << endl;
    else if (num1 < num2)
        cout << "The larger number is " << num2 << endl;
    else
        cout << "Both numbers are equal." << endl;

    return 0;
}