// Example 7-14: String Functions 1 (clear, empty, length, and size)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string firstName = "Elizabeth";
    string name = firstName + " Jones";
    string str1 = "It is sunny.";
    string str2 = "";
    string str3 = "computer science";
    string str4 = "C++ programming.";
    string str5 = firstName + " is taking " + str4;
    string::size_type len;

    cout << "Line 14: str3: " << str3 << endl;
    str3.clear();
    cout << "Line 16: After clear, str3: " << str3 << endl;
    cout << "Line 17: str1.empty(): " << str1.empty() << endl;
    cout << "Line 18: str2.empty(): " << str2.empty() << endl;

    cout << "Line 19: str4: " << str4 << endl;
    str4.erase(11, 4);
    cout << "Line 21: After erase(11, 4), str4: " << str4 << endl;
    
    cout << "Line 22: Length of \"" << firstName << "\" = " << static_cast<unsigned int>(firstName.length()) << endl;
    cout << "Line 23: Length of \"" << name << "\" = " << static_cast<unsigned int>(name.length()) << endl;
    cout << "Line 24: Length of \"" << str1 << "\" = " << static_cast<unsigned int>(str1.length()) << endl;
    cout << "Line 25: Size of \"" << str5 << "\" = " << static_cast<unsigned int>(str5.size()) << endl;

    len = name.length();
    cout << "Line 27: len = " << static_cast<unsigned int>(len) << endl;

    return 0;
}