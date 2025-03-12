#include <iostream>

using namespace std;

int main()
{
	// Variables
	int startingNumber = 0;
	int numberCount = 0;
	int maxCount = 0;

	cout << "Enter the starting number: ";
	cin >> startingNumber;

	cout << "Enter how many numbers to print: ";
	cin >> numberCount;

	while(maxCount < numberCount)
	{
		cout << startingNumber << " ";
		startingNumber++;
		maxCount++;
	}
	cout << endl;

	return 0;
}
