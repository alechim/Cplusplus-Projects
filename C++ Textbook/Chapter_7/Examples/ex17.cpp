// Example 7-17: String Functions 4 (substr)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string sentence = "";
    string str = "";

    sentence = "It is cloudy and warm.";

    cout << "Line 9: substr(0, 5) in \"" << sentence << "\" = \"" << sentence.substr(0, 5) << "\"" << endl; 
    cout << "Line 10: substr(6, 6) in \"" << sentence << "\" = \"" << sentence.substr(6, 6) << "\"" << endl; 
    cout << "Line 11: substr(6, 16) in \"" << sentence << "\" = \"" << sentence.substr(6, 16) << "\"" << endl; 
    cout << "Line 12: substr(17, 10) in \"" << sentence << "\" = \"" << sentence.substr(17, 10) << "\"" << endl; 
    cout << "Line 13: substr(3, 6) in \"" << sentence << "\" = \"" << sentence.substr(3, 6) << "\"" << endl; 

    str = sentence.substr(0, 8);
    cout << "Line 15: str = \"" << str << "\"" << endl; 

    str = sentence.substr(2, 10);
    cout << "Line 17: str = \"" << str << "\"" << endl; 

    return 0;
}