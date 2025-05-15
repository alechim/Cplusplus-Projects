// Example 6-14: Reference and Value Parameters
#include <iostream>

using namespace std;

// ***Function Prototypes***
void funOne(int a, int& b, char v);
void funTwo(int& x, int y, char & w);

int main()
{
    // Variables
    int num1 = 0;
    int num2 = 0;
    char ch = ' ';

    num1 = 10;
    num2 = 15;
    ch = 'A';

    cout << "Line 12: Inside main: num1 = " << num1 << ", num2 = " << num2 << ", and ch = " << ch << endl;

    funOne(num1, num2, ch);
    cout << "Line 14: After funOne: num1 = " << num1 << ", num2 = " << num2 << ", and ch = " << ch << endl;

    funTwo(num2, 25, ch);
    cout << "Line 14: After funTwo: num1 = " << num1 << ", num2 = " << num2 << ", and ch = " << ch << endl;

    return 0;
}

// ***Functions***
void funOne(int a, int& b, char v)
{
    int one = 0;
    one = a;
    a++;
    b = b * 2;
    v = 'B';
    cout << "Line 26: Inside funOne: a = " << a << ", b = " << b << ", v = " << v << ", and one = " << one << endl;
}

void funTwo(int& x, int y, char & w)
{
    x++;
    y = y * 2;
    w = 'G';
    cout << "Line 33: Inside funTwo: x = " << x << ", y = " << y << ", and w = " << w << endl;
}