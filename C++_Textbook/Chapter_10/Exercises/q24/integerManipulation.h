class integerManipulation
{
    public:
        void reverseNum();
        void classifyDigits();
        int sumDigits();
        int splitSum(int);
        void initializePrimes();
        bool checkPrime();
        void findPrimeFactors();

        void setNum(long long n) { num = n; }
        long long getNum() { return num; }
        int getEvensCount() { return evensCount; }
        int getOddsCount() { return oddsCount; }
        int getZerosCount() { return zerosCount; }

        integerManipulation(long long n = 0);
    private: 
        long long num;
        long long revNum;
        int evensCount;
        int oddsCount;
        int zerosCount;

        static int primeNumbers[1230];
};