// Example 6-18: Static and Automatic Variables
#include <iostream>

using namespace std;

// ***Function Prototypes***
void test();

int main()
{
    // Variables
    int count = 0;

    for(count = 1; count <= 5; count++)
        test();
    
    return 0;
}

void test()
{
    static int x = 0;
    int y = 10;
    
    x = x + 2;
    y = y + 1;

    cout << "Inside test x = " << x << " and y = " << y << endl;
}