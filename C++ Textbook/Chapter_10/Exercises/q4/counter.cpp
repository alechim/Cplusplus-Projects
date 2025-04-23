#include "counter.h"

void counterType::incrementCounter() { counter++; }
void counterType::decrementCounter() { counter = ((counter - 1 <= 0) ? 0 : counter - 1); }
void counterType::setCounter(int value) { counter = value; }
int counterType::getCounter() { return counter; }
counterType::counterType(int value) { counter = value; }