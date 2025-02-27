// Question 24: Refactored Classifying Numbers & Makefile
#include <iostream>

using namespace std;

// ***Global Variables***
const int N = 20;

// ***Function Prototypes***
void classify(int number, int& zeros, int& evens, int& odds);

int main(int argc, char* argv[])
{
    // Variables
    int num = 0;
    int zeros = 0;
    int odds = 0;
    int evens = 0;
    
    // Prompt for Input
    cout << "Please enter " << N << " integers, positive, negative, or zeros." << endl;
    cout << "The numbers you entered are: " << endl;
    if(argc > 20)
    {
        for(int i = 0; i < N; i++)
        {
            num = atoi(argv[i + 1]);
            cout << num << " ";
            classify(num, zeros, evens, odds);
        }
    } else
    {
        for(int i = 0; i < N; i++)
        {
            cin >> num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Program Terminating..." << endl;
                return 1;
            }

            cout << num << " ";
            classify(num, zeros, evens, odds);
        }
    }
    
    cout << endl;
    cout << "There are " << evens << " evens, which includes " << zeros << " zeros." << endl;
    cout << "The number of odd numbers is: " << odds << endl;

    return 0;
}

void classify(int number, int& zeros, int& evens, int& odds)
{
    switch(number % 2)
    {
        case 0:
            evens++;
            if(number == 0)
                zeros++;
            break;
        case 1:
        case -1:
            odds++;
    }
}