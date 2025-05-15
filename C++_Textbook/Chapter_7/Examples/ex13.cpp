// Example 7-13: String Operations
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string name = "William Jacob";
    string str1 = "";
    string str2 = "";
    string str3 = "";
    string str4 = "";

    // String Manipulation
    cout << "Line 8: Name = " << name << endl;

    str1 = "Hello There";
    cout << "Line 10: str1 = " << str1 << endl;

    str2 = str1;
    cout << "Line 12: str2 = " << str2 << endl;

    str1 = "Sunny";
    str2  = str1 + " Day";
    cout << "Line 15: str2 = " << str2 << endl;

    str1 = "Hello";
    str2 = "There";
    str3 = str1 + " " + str2;
    cout << "Line 19: str3 = " << str3 << endl;

    str3 = str1 + ' ' + str2;
    cout << "Line 21: str3 = " << str3 << endl;

    str1 = str1 + " Mickey";
    cout << "Line 23: str1 = " << str1 << endl;

    str1 = "Hello there";
    cout << "Line 25: str1[6] = " << str1[6] << endl;

    str1[6] = 'T';
    cout << "Line 27: str1 = " << str1 << endl;

    // String Input Operations
    cout << "Line 28: Enter a string with no blanks: ";
    cin >> str1;

    char ch = ' ';
    cin.get(ch);
    cout << endl;

    cout << "Line 33: The string you entered = " << str1 << endl;
    cout << "Line 34: Enter a sentence: ";
    getline(cin, str2);
    cout << endl;

    cout << "Line 37: The sentence is: " << str2 << endl;

    return 0;
}