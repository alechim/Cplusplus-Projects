// Example 6-B: Global Variables
#include <iostream>

using namespace std;

// ***Globals***
int t = 0;

// ***Function Prototypes***
void funOne(int &a);

int main()
{
    t = 15;
    
    cout << "Line 8: In main: t = " << t << endl;
    funOne(t);
    cout << "Line 10: In main after funOne: t = " << t << endl;

    return 0;
}

// ***Functions***
void funOne(int& a)
{
    cout << "Line 15: In funOne: a = " << a << " and t = " << t << endl;
    a = a + 12;
    cout << "Line 17: In funOne: a = " << a << " and t = " << t << endl;
    t = t + 13;
    cout << "Line 19: In funOne: a = " << a << " and t = " << t << endl;
}