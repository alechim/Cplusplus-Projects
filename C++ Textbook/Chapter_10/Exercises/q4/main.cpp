// Question 4: counterType Class Program
#include <iostream>
#include "counter.h"

using namespace std;

int main() 
{
    // Create a counter initialized to 5
    counterType myCounter(5);
    
    // Display the initial value
    cout << "Initial counter value: " << myCounter.getCounter() << endl;
    
    // Increment the counter a few times
    cout << "\nIncrementing counter 3 times:" << endl;
    for (int i = 0; i < 3; i++) {
        myCounter.incrementCounter();
        cout << "Counter value: " << myCounter.getCounter() << endl;
    }
    
    // Decrement the counter a few times
    cout << "\nDecrementing counter 2 times:" << endl;
    for (int i = 0; i < 2; i++) 
    {
        myCounter.decrementCounter();
        cout << "Counter value: " << myCounter.getCounter() << endl;
    }
    
    // Set the counter to a new value of 10
    cout << "\nSetting counter to 10" << endl;
    myCounter.setCounter(10);
    cout << "Counter value: " << myCounter.getCounter() << endl;
    
    // Test the boundary condition (decrement below 0)
    cout << "\nTesting boundary condition (decrementing to below 0):" << endl;
    myCounter.setCounter(1);
    cout << "Counter set to: " << myCounter.getCounter() << endl;
    
    // Then decrement twice
    myCounter.decrementCounter();
    cout << "After first decrement: " << myCounter.getCounter() << endl;
    
    myCounter.decrementCounter();
    cout << "After second decrement: " << myCounter.getCounter() << endl;
    
    return 0;
}