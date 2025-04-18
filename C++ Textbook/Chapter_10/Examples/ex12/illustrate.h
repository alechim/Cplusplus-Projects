class illustrate
{
    public:
        static int count;       // Public static variable
        
        /**
         * Function to output x, y, and count.
         */
        void print() const;

        /**
         * Function to set x. 
         * Postcondition: x = a;
         */
        void setX(int a);

        /**
         * Static function
         * Function to increment y by 1. 
         * Postcondition: y = y + 1
         */
        static void incrementY();

        /**
         * Constructor
         * Postcondition: x = a;
         * - If no value is specified for a, x = 0;
         */
        illustrate(int a = 0);
    private:
        int x;
        static int y;       // Private static variable
};