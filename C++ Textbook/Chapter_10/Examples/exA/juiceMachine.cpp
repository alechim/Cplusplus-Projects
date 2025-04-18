#include <iostream>
#include "juiceMachine.h"

// =======================
// Class Function Definitions - cashRegister
// =======================
/**
 * cashRegister::getCurrentBalance const: 
 * @return int
 */
int cashRegister::getCurrentBalance() const
{
    return cashOnHand;
}

/**
 * cashRegister::acceptAmount: 
 * @param int amountIn - 
 */
void cashRegister::acceptAmount(int amountIn)
{
    cashOnHand = cashOnHand + amountIn;
}

/**
 * cashRegister::cashRegister: 
 * @param int cashIn - 
 */
cashRegister::cashRegister(int cashIn)
{
    cashOnHand = ((cashIn >= 0) ? cashIn : 500);
}

// =======================
// Class Function Definitions - dispenserType
// =======================
/**
 * dispenserType::getNoOfItems const:
 * @return int - 
 */
int dispenserType::getNoOfItems() const
{
    return numberOfItems;
}

/**
 * dispenserType::getCost const: 
 * @return int - 
 */
int dispenserType::getCost() const
{
    return cost;
}

/**
 * dispenserType::makeSale: 
 */
void dispenserType::makeSale()
{
    numberOfItems--;
}

/**
 * dispenserType::dispenserType
 * @param int setNoOfItems - 
 * @param int setCost - 
 */
dispenserType::dispenserType(int setNoOfItems, int setCost)
{
    numberOfItems = ((setNoOfItems >= 0) ? setNoOfItems : 50);
    cost = ((setCost >= 0) ? setCost : 50);
}