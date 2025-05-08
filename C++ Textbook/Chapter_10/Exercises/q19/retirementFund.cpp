#include <iostream>
#include <iomanip>
#include <cmath>
#include "retirementFund.h"

using namespace std;

/**
 * retirementFund::accumulatedAmount: Calculates and displays the accumulated amount after specified years within the class object
 */
void retirementFund::accumulatedAmount()
{
    // R[((1 + r / m)^(m * t) - 1) / (r / m)]
    double numerator = pow((1 + compoundInterest / timesDeposited), (timesDeposited * years)) - 1;
    double totalCost = periodicDeposit * (numerator / (compoundInterest / timesDeposited));
    cout << "| The total amount accumulated at the end of " << years << ((years == 1) ? " year" : " years") << " is $" << fixed << showpoint << setprecision(2) << totalCost << endl;
}

/**
 * retirementFund::calculatePeriodicPayment: Calculates and displays the periodic payment needed to reach a target amount
 * @param double deposit - Amount deposited each period
 * @param int noOfDeposits - Number of deposits per year
 * @param double interest - Annual interest rate (as a percentage)
 * @param int totalYears - Number of years for investment
 */
void retirementFund::calculatePeriodicPayment(double total, int noOfDeposits, double interest, int totalYears)
{
    // (S(r / m)) / ((1 + r / m)^(m * t) - 1)
    double denom = pow((1 + interest / noOfDeposits), (noOfDeposits * totalYears)) - 1;
    double cost = total * (interest / noOfDeposits) / denom;
    cout << fixed << showpoint << setprecision(2) << "| To accumulate $" << total << " in " << totalYears << ((totalYears == 1) ? " year " : " years "); 
    cout << "with a " << interest * 100.0 << "% interest rate, you need to deposit $" << cost << " every " << noOfDeposits << " times a year." << endl;
}

/**
 * retirementFund::retirementFund: Default Constructor
 * @param double deposit - Amount deposited each period
 * @param int noOfDeposits - Number of deposits per year
 * @param double interest - Annual interest rate (as a percentage)
 * @param int totalYears - Number of years for investment
 */
retirementFund::retirementFund(double deposit, int noOfDeposits, double interest, int totalYears)
{
    setDeposit(deposit);
    setTimesDeposit(noOfDeposits);
    setInterest(interest);
    setYears(totalYears);
}