class counterType
{
    public:
        void incrementCounter();
        void decrementCounter();
        void setCounter(int);
        int getCounter();
        counterType(int = 0);

    private:
        int counter;
};