// Example 8-10: C-String Functions
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    // Variables
    char studentName[21];
    char myName[16];
    char yourName[16];
    
    // +=============                       +==========
    // | Statement                          | Effect
    // +=============                       +==========
    strcpy(myName, "John Robinson");        // myName = "John Robinson"
    strlen("John Robinson");                // Returns `13`, the length of the string

    int len;
    len = strlen("Sunny Day");              // Stores `9` into `len`

    strcpy(yourName, "Lisa Miller");        // yourName = "Lisa Miller"
    strcpy(studentName, yourName);          // studentName = "Lisa Miller"

    strcmp("Bill", "Lisa");                 // Returns a value `< 0`

    strcpy(yourName, "Kathy Brown");        // yourName = "Kathy Brown"
    strcpy(myName, "Mark G. Clark");        // myName = "Mark G. Clark"

    strcmp(myName, yourName);               // Returns a value `> 0`

    return 0;
}