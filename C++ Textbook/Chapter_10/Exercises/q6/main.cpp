// Question 6: Convert Roman Numerals to Integers
#include <iostream>
#include "romanType.h"

using namespace std;

int main()
{
    // Test program using 'MCXIV', 'CCCLIX', and 'MDCLXVI'
    romanType roman("MCXIV");

    cout << endl;
    cout << "Numeral: " << roman.getNumeral() << "\t\t";
    roman.convertNumeral();
    cout << "Value: " << roman.getNumericValue() << endl << endl;

    roman.setNumeral("CCCLIX");
    cout << "Numeral: " << roman.getNumeral() << "\t\t";
    roman.convertNumeral();
    cout << "Value: " << roman.getNumericValue() << endl << endl;

    roman.setNumeral("MDCLXVI");
    cout << "Numeral: " << roman.getNumeral() << "\t";
    roman.convertNumeral();
    cout << "Value: " << roman.getNumericValue() << endl << endl;

    return 0;
}