#ifndef INTEGER_MANIPULATION_H
#define INTEGER_MANIPULATION_H

class integerManipulation
{
    public:
        void setNum(long long n);
        long long getNum();

        void reverseNum();
        void classifyDigits();

        int getEvensCount();
        int getOddsCount();
        int getZerosCount();
        int sumDigits();

        integerManipulation(long long n = 0);

    private: 
        long long num;
        long long revNum;
        int evensCount;
        int oddsCount;
        int zerosCount;
};

#endif