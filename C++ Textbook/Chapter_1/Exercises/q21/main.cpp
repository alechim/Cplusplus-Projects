// Question 21: Find the roots of a quadratic equation
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Variables
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double positiveRoot = 0;
    double negativeRoot = 0;

    while(true)
    {
        cout << "Enter a non-zero real number for a: ";
        cin >> a;

        if(cin.fail() || a == 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero double value." << endl;
            continue;
        }

        cout << "Enter a real number for b: ";
        cin >> b;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a real number double value." << endl;
            continue;
        }

        cout << "Enter a real number for c: ";
        cin >> c;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a real number double value." << endl;
            continue;
        }

        break;
    }

    double discriminant = pow(b, 2) - (4 * a * c);
    if(discriminant < 0)
    {
        cout << "The equation " << a << "x^2 + " << b << "x + " << c << " = 0 has no real roots." << endl;
    } else {
        positiveRoot = (-b + sqrt(discriminant)) / (2 * a);
        negativeRoot = (-b - sqrt(discriminant)) / (2 * a);
    
        cout << "The equation " << a << "x^2 + " << b << "x + " << c << " = 0 has the roots " << positiveRoot << " and " << negativeRoot << "." << endl;
    }

    return 0;
}