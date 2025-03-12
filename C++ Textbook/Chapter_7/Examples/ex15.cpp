// Example 7-15: String Functions 2 (find)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string sentence = "Outside it is cloudy and warm.";
    string str = "cloudy";

    string::size_type position;

    cout << "Line 9: sentence = \"" << sentence << "\"" << endl;
    cout << "Line 10: The position of \"is\" in sentence = " << static_cast<unsigned int>(sentence.find("is")) << endl; 
    cout << "Line 11: The position of 's' in sentence = " << static_cast<unsigned int>(sentence.find('s')) << endl; 
    cout << "Line 12: The position of \"" << str << "\" in sentence = " << static_cast<unsigned int>(sentence.find(str)) << endl; 
    cout << "Line 13: The position of \"the\" in sentence = " << static_cast<unsigned int>(sentence.find("the")) << endl; 
    cout << "Line 14: The first occurence of \'i\' in sentence \n         after position 6 = " << static_cast<unsigned int>(sentence.find('i', 6)) << endl;

    position = sentence.find("warm");
    cout << "Line 16: Position = " << position << endl;

    return 0;
}