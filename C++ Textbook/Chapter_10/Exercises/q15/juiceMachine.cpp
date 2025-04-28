#include <iostream>
#include "juiceMachine.h"

// =======================
// Class Function Definitions - cashRegister
// =======================
/**
 * cashRegister::getCurrentBalance const: Returns the variable cashOnHand of the class
 * @return int - cashOnHand of the class object
 */
int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
}

/**
 * cashRegister::acceptAmount: Updates the variable cashOnHand by adding the passed parameter into it
 * @param int amountIn - The value to be added to the instance variable cashOnHand
 */
void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}

/**
 * cashRegister::cashRegister: Constructor with parameters
 * @param int cashIn - The variable to intialize cashOnHand if not negative. Otherwise, intialize to 50.
 */
cashRegister::cashRegister(int cashIn)
{
    cashOnHand = ((cashIn >= 0) ? cashIn : 500);
}

// =======================
// Class Function Definitions - dispenserType
// =======================
/**
 * dispenserType::getNoOfItems const: Returns the instance variable numberOfItems of the class
 * @return int - numberOfItems of the class object
 */
int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}

/**
 * dispenserType::getCost const: Returns the instance variable cost of the class
 * @return int - cost of the class object
 */
int dispenserType::getCost() const
{
    return cost;
}

/**
 * dispenserType::makeSale: Decrements the instance variable numberOfItems when called
 */
void dispenserType::makeSale()
{
    numberOfItems--;
}

/**
 * dispenserType::dispenserType: Constructor with parameters
 * @param int setNoOfItems - The variable to intialize numberOfItems if not negative. Otherwise, intialize to 50.
 * @param int setCost - The variable to intialize cost if not negative. Otherwise, intialize to 50.
 */
dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    numberOfItems = ((setNoOfItems >= 0) ? setNoOfItems : 50);
    cost = ((setCost >= 0) ? setCost : 50);
}