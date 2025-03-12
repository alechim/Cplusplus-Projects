#include <iostream>

using namespace std;

int main()
{
	// Variables
	int limit = 0;

	cout << "For Loop" << endl;
	for(limit = 0; limit < 5; limit++)
		cout << "Hello ";

	limit = 0;
	cout << endl << "\nWhile Loop" << endl;
	while(limit < 5)
	{
		cout << "Hello ";
		limit++;
	}

	limit = 0;
	cout <<  endl << "\nDo While Loop" << endl;
	do
	{
		cout << "Hello ";
		limit++;
	} while(limit < 5);
	cout << endl;

	return 0;
}
