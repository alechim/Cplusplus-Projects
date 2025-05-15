/**
 * @class cashRegister: Specifies the members to implement a cash register
 */
class cashRegister
{
    public: 
        /**
         * Function to show the current amount in the cash register. 
         * Postcondition: The value of cashOnHand is returned.
         */
        int getCurrentBalance() const;

        /**
         * Function to receive the amount deposited by the customer and update the amount in the register. 
         * Postcondition: cashOnHand = cashOnHand + amountIn;
         */
        void acceptAmount(int amountIn);

        /**
         * Constructor
         * Sets the cash in the register to a specific amount.
         * Postcondition: cashOnHand = cashIn;
         * - If no value is specified when the object is declared, the default value assigned to cashOnHand is 500.
         */
        cashRegister(int cashIn = 500);
    private:
        int cashOnHand;     // Variable to store the cash in the register
};

/**
 * @class dispenserType: Specifies the members to implement a dispenser
 */
class dispenserType
{
    public: 
        /**
         * Function to show the number of items in the machine. 
         * Postcondition: The value of numberOfItems is returned.
         */
        int getNoOfItems() const;

        /**
         * Function to show the cost of the item. 
         * Postcondition: The value of cost is returned. 
         */
        int getCost() const;
        
        /**
         * Function to reduce the number of items by 1.
         * Postcondition: numberOfItems--;
         */
        void makeSale();

        /**
         * Constructor
         * Sets the cost and number of items in the dispenser to the values specified by the user. 
         * Postcondition: numberOfItems = setNoOfItems; cost = setCost;
         * - If no value is specified for a parameter, then its default value is assigned to the corresponding
         *   member variable.
         */
        dispenserType(int setNoOfItems = 50, int setCost = 50);
    private:
        int numberOfItems;      // Variable to store the number of items in the dispenser
        int cost;               // Variable to store the cost of an item
};