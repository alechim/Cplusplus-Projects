// Example 3-7: Peek and Putback Functions
#include <iostream>

using namespace std;

int main()
{
    // Variables
    char ch;

    cout << "Line 6: Enter a string: ";
    cin.get(ch);
    cout << endl;
    cout << "Line 9: After first cin.get(ch); ch = " << ch << endl;
    cin.get(ch);
    cout << "Line 11: After second cin.get(ch); ch = " << ch << endl; 
    
    cin.putback(ch);
    cin.get(ch);
    cout << "Line 14: After putback and then cin.get(ch); ch = " << ch << endl;
    ch = cin.peek();
    cout << "Line 16: After cin.peek(); ch = " << ch << endl;
    cin.get(ch);
    cout << "Line 18: After cin.get(ch); ch = " << ch << endl; 

    return 0;
}