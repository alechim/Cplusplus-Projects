// Question 22: Math Class Cost
/**
 * Given:
 * - Miss Monday Math Class (15 days missed | 30 days attended)
 * - Tuition: $25k
 * - Average Semester: 15 units
 * - Math class meets 3 days a week, 1 hour, 15 weeks total
 * - Math class is a 4 unit course
 * Solve:
 * - How much does each hour of math class cost the student?
 */
/**
 * Algorithm:
 * - Calculate tuition cost per unit
 * - Use calculation to find cost of math class per semester
 * - Calculate the cost of day (hour) based on math class tuition
 * - Multiply calculation by 15 to find out how much 15 days of class missed
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double semesterTuition = 25000.00;
    double unitCost = semesterTuition / 15.00;
    double mathTuition = unitCost * 4.00;
    double mathDaily = mathTuition / 45.00;

    cout << fixed << setprecision(2);
    cout << "The cost of math class per semester is $" << mathTuition << "." << endl;
    cout << "Each math class costs $" << mathDaily << "." << endl;
    cout << "Missing 15 days of math class costs $" << mathDaily * 15 << endl;

    return 0;
}