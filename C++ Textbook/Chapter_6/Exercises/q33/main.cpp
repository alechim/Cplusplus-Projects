// Question 33: Refactored 6-16
#include <iostream>
#include <cmath>

using namespace std;

// ***Function Prototypes***
void promptInput(int& value, const string prompt);
void factorization(int a, int b, int c, int u[2], int v[2], bool& isFactorable);
int gcd(int a, int b);
void displayFactorization(int a, int b, int c,int u[2], int v[2], bool isFactorable);

int main()
{
    // Variables
    int coeffOfX2 = 0;
    int coeffOfX = 0;
    int constantTerm = 0;
    int u[2];   // 0: numerator, 1: denominator
    int v[2];
    bool isPolynomialFactorable = false;

    // Prompt for Input
    promptInput(coeffOfX2, "Enter the coefficient of x^2: ");
    promptInput(coeffOfX, "Enter the coefficient of x: ");
    promptInput(constantTerm, "Enter the constant term: ");

    // Check if formula is valid
    if(coeffOfX2 == 0)
    {
        cout << "This equation is linear and cannot be factored with the quadratic formula." << endl;
        return 0;
    }

    // Calculate Polynomial
    factorization(coeffOfX2, coeffOfX, constantTerm, u, v, isPolynomialFactorable);

    // Display Results
    displayFactorization(coeffOfX2, coeffOfX, constantTerm, u, v, isPolynomialFactorable);
    
    return 0;
}

// ***Functions***
void promptInput(int& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while(true);
}

void factorization(int a, int b, int c, int u[2], int v[2], bool& isFactorable)
{
    double discriminant = 0.0;
    
    isFactorable = true;
    discriminant = b * b - 4 * a * c;

    if(discriminant < 0)
        isFactorable = false;
    else
    {
        int sqrtDiscriminant = static_cast<int>(sqrt(discriminant));
        if(sqrtDiscriminant * sqrtDiscriminant != discriminant)
            isFactorable = false;
        else
        {
            u[0] = (-b + sqrtDiscriminant) / gcd((-b + sqrtDiscriminant), (2 * a));
            u[1] = (2 * a) / gcd((-b + sqrtDiscriminant), (2 * a));
            v[0] = (-b - sqrtDiscriminant) / gcd((-b - sqrtDiscriminant), (2 * a));
            v[1] = (2 * a) / gcd((-b - sqrtDiscriminant), (2 * a));

            // Adjust sign if denominator is negative 
            if(u[1] < 0)
            {
                u[0] = -u[0];
                u[1] = -u[1];
            }
            if(v[1] < 0)
            {
                v[0] = -v[0];
                v[1] = -v[1];
            }
        }
    }
}

int gcd(int a, int b)
{
    // Convert negative values
    a = abs(a);
    b = abs(b);

    // Case: gcd is found
    if(a % b == 0)
        return b;

    // Recursion
    return gcd(b, a % b);
}

void displayFactorization(int a, int b, int c, int u[2], int v[2], bool isFactorable)
{
    if(isFactorable)
    {
        // Display the original polynomial
        if(a == 1)
            cout << "x^2";
        else if(a == -1)
            cout << "-x^2";
        else
            cout << a << "x^2"; 

        if(b > 0)
            cout << " + " << b << "x";
        else if(b < 0)
            cout << " - " << abs(b) << "x";

        if(c > 0)
            cout << " + " << c;
        else if(c < 0)
            cout << " - " << abs(c);
        cout << " = (";

        // Display factors
        if(u[0] == -1)
            cout << "-x";
        else if(u[0] == 1)
            cout << "x";
        else
            cout << u[0] << "x";
        
        if(u[1] > 0)
            cout << " + " << u[1] << ")(";
        else if(u[1] < 0)
            cout << " - " << abs(u[1]) << ")(";

        if(v[0] == -1)
            cout << "-x";
        else if(v[0] == 1)
            cout << "x";
        else
            cout << v[0] << "x";

        if(v[1] > 0)
            cout << " + " << v[1] << ")\n";
        else if(v[1] < 0)
            cout << " - " << abs(v[1]) << ")\n";

    } else {
        cout << "The polynomial is not factorable with rational coefficients." << endl;
    }
}