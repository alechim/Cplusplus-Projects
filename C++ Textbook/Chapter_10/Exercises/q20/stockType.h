#include <string>

class stockType
{
    public:
        void print();
        double percentGainLoss();

        // Inline Setters and Getters
        void setStockName(std::string value) { name = value; }
        std::string getName() const { return name; }

        void setSymbol(std::string value) { symbol = value; }
        std::string getSymbol() const { return symbol; }

        void setCurrentPrice(double value) { currentPrice = value; }
        double getCurrentPrice() const { return currentPrice; }

        void setLowPriceOfTheDay(double value) { lowPriceOfTheDay = value; }
        double getLowPriceOfTheDay() const { return lowPriceOfTheDay; }

        void setHighPriceOfTheDay(double value) { highPriceOfTheDay = value; }
        double getHighPriceOfTheDay() const { return highPriceOfTheDay; }

        void setPreviousDayClosingPrice(double value) { previousDayClosingPrice = value; }
        double getPreviousDayClosingPrice() const { return previousDayClosingPrice; }

        void setFiftyTwoWeeksHigh(double value) { fiftyTwoWeeksHigh = value; }
        double getFiftyTwoWeeksHigh() const { return fiftyTwoWeeksHigh; }

        void setFiftyTwoWeeksLow(double value) { fiftyTwoWeeksLow = value; }
        double getFiftyTwoWeeksLow() const { return fiftyTwoWeeksLow; }

        stockType(std::string = "", std::string = "", double = 0.0, double = 0.0, double = 0.0, double = 0.0, double = 0.0, double = 0.0);
    private:
        std::string name;
        std::string symbol;
        double currentPrice;
        double lowPriceOfTheDay;
        double highPriceOfTheDay;
        double previousDayClosingPrice;
        double fiftyTwoWeeksHigh;
        double fiftyTwoWeeksLow;
};