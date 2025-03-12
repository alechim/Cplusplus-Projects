/* Alec Him, 2001543593, CS135 1004, Worksheet 4
 * Description: Inputs two Integers and adds the Total
 * Input: Integers
 * Output: Displays the sum of two Integers 
 */
#include <iostream>

using namespace std;

int main()
{
	// Variables
	int a = 0;
	int b = 0;
	int ans = 0;

	cout << "Enter two integers to sum: ";
	cin >> a >> b;

	ans = a + b;

	cout << "The sum of " << a << " + " << b << " = " << ans << endl;

	return 0;
}