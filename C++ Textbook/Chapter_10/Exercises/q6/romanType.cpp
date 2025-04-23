#include <string>
#include "romanType.h"

using namespace std;

/**
 * romanType::convertNumeral: Takes the class instance variable of the roman numeral and converts it to a positive integer value
 *                            which is stored in the other instance variable, numericValue.
 */
void romanType::convertNumeral()
{
    for(int i = 0; i < numeral.size(); i++)
        switch(numeral[i])
        {
            case 'M':   
                numericValue += 1000;
                break;
            case 'D':
                numericValue += 500;
                break;
            case 'C':
                numericValue += 100;
                break;
            case 'L':
                numericValue += 50;
                break;
            case 'X':
                numericValue += 10;
                break;
            case 'V':
                numericValue += 5;
                break;
            case 'I':
                if(numeral.size() - i - 1 <= 0 && (numeral[i + 1] != 'X' && numeral[i + 1] != 'V'))
                {
                    numericValue += 1;
                    break;
                }
                if(numeral[i + 1] == 'X')
                    numericValue += 9;
                else if(numeral[i + 1] == 'V')
                    numericValue += 4;
                i++;
                break;
            default:
                break;
        }
}

/**
 * +==== Class Setters and Getters ====+
 */
void romanType::setNumeral(string value) { 
    numeral = value; 
    numericValue = 0;       // When setting a new numeral, the numeric value must be reset to 0.
}
string romanType::getNumeral() { return numeral; }
int romanType::getNumericValue() { return numericValue; }

/**
 * romanType::romanType: Constructor with 1 parameter
 * @param string value - The string containing the roman numeral
 */
romanType::romanType(string value)
{
    numeral = value;
    numericValue = 0;
}