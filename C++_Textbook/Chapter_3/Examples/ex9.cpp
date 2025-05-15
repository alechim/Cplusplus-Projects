// Example 3-9: Input Failure Program
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string name = "";
    int age = 0;
    int weight = 0;
    double height = 0.0;

    cout << "Line 10: Enter name, age, weight, and height: ";
    cin >> name >> age >> weight >> height;
    cout << endl;

    cout << "Line 13: Name: " << name << endl;
    cout << "Line 14: Age: " << age << endl;
    cout << "Line 15: Weight: " << weight << endl;
    cout << "Line 16: Height: " << height << endl;

    cin.clear();            // Restore input stream
    cin.ignore(200, '\n');  // Clear the buffer

    cout << "\nLine 19: Enter name, age, weight, and height: ";
    cin >> name >> age >> weight >> height;
    cout << endl;

    cout << "Line 22: Name: " << name << endl;
    cout << "Line 23: Age: " << age << endl;
    cout << "Line 24: Weight: " << weight << endl;
    cout << "Line 25: Height: " << height << endl;

    return 0;
}