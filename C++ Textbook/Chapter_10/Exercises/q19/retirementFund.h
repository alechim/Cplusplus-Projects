class retirementFund
{
    public:
        void accumulatedAmount();
        void calculatePeriodicPayment(double, int, double, int);

        // Inline Setters and Getters
        void setDeposit(double value) { periodicDeposit = value; }
        double getDeposit() const { return periodicDeposit; }
        void setTimesDeposit(int value) { timesDeposited = value; }
        int getTimesDeposit() const { return timesDeposited; }
        void setInterest(double value) { compoundInterest = value; }
        double getInterest() const { return compoundInterest; }
        void setYears(int value) { years = value; }
        int getYears() const { return years; }

        retirementFund(double = 0.0, int = 0, double = 0.0, int = 0);
    private:
        double periodicDeposit;
        int timesDeposited;
        double compoundInterest;
        int years;
};