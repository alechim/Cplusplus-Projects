// Question 5: Calculate Federal Tax
/**
 * Given:
 * - Standard Exemption
 *   > Single People, $4000
 *   > Married People, $7000
 *     - At least Two children under 14, personal exemption = $1,500 * 4 
 * - Pension Plan, up to 6% of gross income
 * - Taxable Income
 *   > $0 - $15,000: 15% Tax Rate
 *   > $15,001 - $40,000: $2,250 + 25% of taxable income over 15,000
 *   > Over $40,000: $8,460 + 35% of taxable income over $40,000
 */
#include <iostream>
#include <iomanip>

using namespace std;

// Function Prototypes
void getData(string&, int&, double&, double&);
double taxAmount(string, int, double, double);

int main()
{
    // Variables
    string status = "";
    int noOfChildren = 0;
    double salary = 0.0;
    double pensionPercent = 0.0;

    // Prompt for Input
    getData(status, noOfChildren, salary, pensionPercent);

    // Calculations and Display Results
    cout << "Federal Tax: " << fixed << showpoint << setprecision(2) << "$" << taxAmount(status, noOfChildren, salary, pensionPercent);

    return 0;
}

// Function Definitions
/**
 * getData: Prompts the users for all of the following passed parameters
 * @param string status - contains the marital status 
 * @param int noOfChildren - contains the number of children a married couple has
 * @param double salary - the gross salary of the individual; combined gross salary if married
 * @param double pensionPercent - contains the percentage of gross income contributed to a pension fund
 */
void getData(string& status, int& noOfChildren, double& salary, double& pensionPercent)
{
    // Prompt Marital Status
    do
    {
        cout << "Enter your marital status (Single or Married): ";
        cin >> status;
        if(cin.fail() || (status != "Single" && status != "single" && status != "Married" && status != "married"))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter whether you are single or married." << endl;
        } else
            break;
    } while(true);
    
    // If married, prompt for # of children
    if(status == "Married" || status == "married")
    {
        do
        {
            cout << "Please enter the number of your children that are under 14: ";
            cin >> noOfChildren;
            
            if(cin.fail() || noOfChildren < 0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a positive integer value." << endl;
            } else  
                break;
        } while(true);
    }

    // Prompt Gross Salary
    double temp = 0.0;
    do
    {
        if(status == "Married" || status == "married")
        {
            cout << "Enter the first spouse's gross salary: $";
            cin >> temp;
            if(cin.fail() || temp < 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a positive double value." << endl;
                continue;
            } 
            cout << "Enter the second spouse's gross salary: $";
        } else
            cout << "Enter your gross salary: $";
        
        cin >> salary;
        if(cin.fail() || salary < 0.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive double value." << endl;
        } else
        {
            salary += temp;
            break;
        }
    } while(true);

    // Prompt for Percentage of gross income contributed to a pension fund
    do
    {
        cout << "Enter the total percentage (up to 6%) of gross income used to contribute to a pension fund (%): ";
        cin >> pensionPercent;

        if(cin.fail() || pensionPercent <= 0.0 || pensionPercent > 6.0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
        } else
            break;
    } while(true);
}

/**
 * taxAmount: Uses the passed parameters to perform the calculations of federal tax
 * @param string status - contains the marital status 
 * @param int noOfChildren - contains the number of children a married couple has
 * @param double salary - the gross salary of the individual; combined gross salary if married
 * @param double pensionPercent - contains the percentage of gross income contributed to a pension fund
 * @return double taxRate
 */
double taxAmount(string status, int noOfChildren, double salary, double pensionPercent)
{
    // Variables
    double taxableIncome = 0.0;
    double standardExemption = 0.0;
    double personalExemption = 0.0;

    // Find Standard and Personal Exemption
    if(status == "Married" || status == "married")
    {
        standardExemption = 7'000.00;
        personalExemption = 1'500.00 * (2 + noOfChildren);
    }    
    else
    {
        standardExemption = 4'000.00;
        personalExemption = 1'500.00;
    }

    // Calculate Taxable Income
    taxableIncome = salary - standardExemption - (salary * (pensionPercent / 100)) - personalExemption;
    if(taxableIncome < 0.0) taxableIncome = 0.0;

    // Determine federal tax that must be repaid
    if(taxableIncome <= 15'000.00)
        return 0.15 * taxableIncome;
    else if(taxableIncome >= 15'001.00 && taxableIncome < 40'000.00)
        return 2'250.00 + (0.25 * (taxableIncome - 15'000.00)); 
    
    return 8'460.00 + (0.35 * (taxableIncome - 40'000.00));
}