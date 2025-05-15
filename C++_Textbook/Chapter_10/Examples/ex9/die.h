class die
{
    public:
        /**
         * Default constructor
         * Sets the default number rolled by a die to 1
         */
        die();

        /**
         * Function to roll a die.
         * This function uses a random number generator to randomly generate a number between 1 and 6,
         * and stores the number in the instance variable num. 
         */
        void roll();

        /**
         * Function to return the number on the top face of the die. 
         * Returns the value of the instance variable num.
         */
        int getNum() const;
    private:
        int num;
};