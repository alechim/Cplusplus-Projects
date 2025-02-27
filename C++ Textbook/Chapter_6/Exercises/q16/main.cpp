// Question 16: Function Practice 1
#include <iostream>
#include <iomanip>

using namespace std;

// ***Function Prototypes***
void initialize(int& x, int& y, char& z);
void getHoursRate(double& hours, double& rate);
double payCheck(double hours, double rate);
void printCheck(double hours, double rate, double salary);
void funcOne(int& x, int y);
void nextChar(char& z);

int main()
{
    // Variables
    int x, y;
    char z;
    double rate, hours;
    double amount;

    initialize(x, y, z);
    getHoursRate(hours, rate);
    amount = payCheck(hours, rate);
    printCheck(hours, rate, amount);

    x = 4;
    y = 8;
    z = 'A';

    cout << "Before funcOne: x = " << x << ", y = " << y << endl;
    funcOne(x, y);
    cout << "After funcOne: x = " << x << ", y = " << y << endl;

    cout << "Before nextChar: z = \'" << z << "\'\n";
    nextChar(z);
    cout << "After nextChar: z = \'" << z << "\'\n";

    return 0;
}

// ***Functions***
void initialize(int& x, int& y, char& z)
{
    x = 0;
    y = 0;
    z = ' ';
}

void getHoursRate(double& hours, double& rate)
{
    do
    {
        cout << "Enter your hours worked: ";
        cin >> hours;
        if(cin.fail() || hours <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            continue;
        }

        cout << "Enter your rate per hour: $";
        cin >> rate;
        if(cin.fail() || rate <= 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}

double payCheck(double hours, double rate)
{
    double check = 0.0;
    if(hours < 40)
        check = hours * rate;
    else
        check = (40 * rate) + ((hours - 40) * (rate * 1.5));
    return check;
}

void printCheck(double hours, double rate, double salary)
{
    cout << "Hours worked: " << hours << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "Hourly Rate: $" << rate << endl;
    cout << "Salary: $" << salary << endl;
}

void funcOne(int& x, int y)
{
    int num = 0;
    do
    {
        cout << "Enter an integer value: ";
        cin >> num;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter an integer value." << endl;
        } else
            break;
    } while(true);
    
    x = (2 * x) + y - num;
}

void nextChar(char& z)
{
    z += 1;
}