// Example 11-5: Accessing protected Members in the Derived Class
#include <iostream>
#include "bClass.h"
#include "dClass.h"

using namespace std;

int main()
{
    bClass bObject;
    dClass dObject;

    bObject.print();
    cout << endl;

    cout << "*** Derived class object ***" << endl;
    dObject.setData('&', 2.5, 7);
    dObject.print();

    // Illegal Operation: dObject.bCh = '&';
    // Protected Member Variables cannot be accessed directly

    return 0;
}