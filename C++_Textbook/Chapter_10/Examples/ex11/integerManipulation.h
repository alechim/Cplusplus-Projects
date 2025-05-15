class integerManipulation
{
    public:
        /**
         * Function to set num. 
         * Postcondition: num = n;
         */
        void setNum(long long n);

        /**
         * Function to return num. 
         * Postcondition: The value of num is returned. 
         */
        long long getNum();

        /**
         * Function to reverse the digits of num. 
         * Postcondition: revNum is set to num with digits in the reverse order. 
         */
        void reverseNum();

        /**
         * Function to count the even, odd, and zero digits of num. 
         * Postcondition: evenCount = the number of even digits in num. 
         * - oddCount = the number of odd digits in num. 
         */
        void classifyDigits();

        /**
         * Function to return the number of even digits in num. 
         * Postcondition: The value of evensCount is returned.
         */
        int getEvensCount();

        /**
         * Function to return the number of odd digits in num. 
         * Postcondition: The value of oddsCount is returned.
         */
        int getOddsCount();

        /**
         * Function to return the number of zeros in num. 
         * Postcondition: The value of zerosCount is returned.
         */
        int getZerosCount();

        /**
         * Function to return the sum of the digits of num. 
         * Postcondition: The sum of the digits is returned.
         */
        int sumDigits();

        /**
         * Constructor with a default parameter. 
         * The instance variable num is set according to the parameter, and other instance variables are set to zero. 
         * The default value of num is 0;
         * Postcondition: num = n; revNum = 0; evensCount = 0; oddsCount = 0; zerosCount = 0;
         */
        integerManipulation(long long n = 0);
    private: 
        long long num;
        long long revNum;
        int evensCount;
        int oddsCount;
        int zerosCount;
};