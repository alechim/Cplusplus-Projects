// Example 6-19: Default Parameters
#include <iostream>
#include <iomanip>

using namespace std;

// ***Function Prototypes***
int volume(int l = 1, int w = 1, int h = 1);
void funcOne(int& x, double y = 12.34, char z = 'B');

int main()
{
    // Variables
    int a = 23;
    double b = 48.78;
    char ch = 'M';

    cout << fixed << showpoint << setprecision(2);
    cout << "Line 12: a = " << a << ", b = " << b << ", ch = " << ch << endl;
    cout << "Line 13: Volume = " << volume() << endl;
    cout << "Line 14: Volume = " << volume(5, 4) << endl;
    cout << "Line 15: Volume = " << volume(34) << endl;
    cout << "Line 16: Volume = " << volume(6, 4, 5) << endl;

    funcOne(a);
    funcOne(a, 42.68);
    funcOne(a, 34.65, 'Q');
    cout << "Line 20: a = " << a << ", b = " << b << ", ch = " << ch << endl;

    return 0;
}

// ***Functions***
int volume(int l, int w, int h)
{
    return l * w * h;
}

void funcOne(int &x, double y, char z)
{
    x = 2 * x;
    cout << "Line 30: x = " << x << ", y = " << y << ", z = " << z << endl;
}