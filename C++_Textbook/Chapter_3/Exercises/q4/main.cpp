// Question 4: Fertilizer Price Calculator
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Variables
    double cost = 0.0;
    double area = 0.0;
    double bagSize = 0.0;

    cout << "Enter the amount of fertilizer, in pounds, in one bag: ";
    cin >> bagSize;
    cout << endl;

    cout << "Enter the cost of the " << bagSize << " pound fertilizer bag: ";
    cin >> cost;
    cout << endl;

    cout << "Enter the area, in square feet, that can be fertilized by one bag: ";
    cin >> area;
    cout << endl;

    cout << fixed << showpoint << setprecision(2);
    cout << "The cost of the fertilizer per pound is: $" << bagSize / cost << endl;
    cout << "The cost of fertilizing per square foot is: $" << cost / area << endl;

    return 0;
}