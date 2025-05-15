// Example 7-16: String Functions 3 (insert and replace)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Variables
    string firstString = "Cloudy and warm.";
    string secondString = "Hello there";
    string thirdString = "Henry is in programming I.";
    string str1 = " very";
    string str2 = "Lisa";

    cout << "Line 11: firstString = " << firstString << endl;
    firstString.insert(10, str1);

    cout << "Line 13: After insert; firstString = " << firstString << endl;
    
    cout << "Line 14: secondString = " << secondString << endl;
    secondString.insert(11, 5, '!');
    cout << "Line 16: After insert; secondString = " << secondString << endl;

    cout << "Line 17: thirdString = " << thirdString << endl;
    thirdString.replace(0, 5, str2);
    cout << "Line 19: After replace, thirdString = " << thirdString << endl;

    return 0;
}