// Example 6-16: Second Degree Polynomial Factorization
#include <iostream>
#include <cmath>

using namespace std;

// ***Function Prototypes***
void factorization(int b, int c, int& u1, int& v1, bool& isFactorable);

int main()
{
    // Variables
    int coeffOfX = 0;
    int constantTerm = 0;
    int u = 0;
    int v = 0;
    bool isPolynomialFactorable = false;

    // Prompt for Input
    cout << "Enter the coefficient of x: ";
    cin >> coeffOfX;
    cout << endl;

    cout << "Enter the constant term: ";
    cin >> constantTerm;
    cout << endl;

    factorization(coeffOfX, constantTerm, u, v, isPolynomialFactorable);

    if(isPolynomialFactorable)
    {
        cout << "x^2";
        if(coeffOfX > 0)
            cout << " + " << coeffOfX << "x";
        else if(coeffOfX < 0)
            cout << " - " << abs(coeffOfX) << "x";

        if(constantTerm > 0)
            cout << " + " << constantTerm;
        else if(constantTerm < 0)
            cout << " - " << abs(constantTerm);
    
        cout << " = (x";
        if(u > 0)
            cout << " - " << u << ")(x";
        else if(u < 0)
            cout << " + " << abs(u) << ")(x";
        
        if(v > 0)
            cout << " - " << v << ")" << endl;
        else if(v < 0)
            cout << " + " << abs(v) << ")" << endl;
    } else
        cout << "The polynomial is not factorable." << endl;

    return 0;
}

// ***Functions***
void factorization(int b, int c, int& u1, int& v1, bool& isFactorable)
{
    double discriminant = 0.0;
    int temp = 0;
    
    isFactorable = true;

    discriminant = b * b - 4 * c;

    if(discriminant < 0)
        isFactorable = false;
    else
    {
        temp = static_cast<int>(sqrt(discriminant));
        if(temp * temp != discriminant)
            isFactorable = false;
        else
        {
            if(((-b + temp) % 2 != 0) || ((-b - temp) % 2 != 0))
                isFactorable = false;
            else
            {
                u1 = (-b + temp) / 2;
                v1 = (-b - temp) / 2;
            }
        }
    }
}