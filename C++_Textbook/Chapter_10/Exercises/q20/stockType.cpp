#include <iostream>
#include <iomanip>
#include "stockType.h"

using namespace std;

// Class Function Definitions
/**
 * stockType::print: Output the data stored in the member variables with appropriate titles
 */
void stockType::print()
{
    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;
    cout << "| Stock Name: " << name << endl;
    cout << "| Stock Symbol: " << symbol << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << "| Stock Price: $" << currentPrice << endl;
    cout << "| Lowest Price of the Day: $" << lowPriceOfTheDay << endl;
    cout << "| Highest Price of the Day: $" << highPriceOfTheDay << endl;
    cout << "| Previous Day Closing Price: $" << previousDayClosingPrice << endl;
    cout << "| Fifty Two Weeks Highest Price: $" << fiftyTwoWeeksHigh << endl;
    cout << "| Fifty Two Weeks Lowest Price: $" << fiftyTwoWeeksLow << endl;
    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;
}

/**
 * stockType::percentGainLoss: determine the percentage gain or loss between the current price and previous day closing price 
 */
double stockType::percentGainLoss()
{
    // Percent of Change: [(New - Old) / Old] * 100
    return ((currentPrice - previousDayClosingPrice) / previousDayClosingPrice) * 100;
}

/**
 * stockType::stockType: Default Constructor
 * @param string stockName - The name of the stock/company
 * @param string stockSymbol - The ticker symbol for the stock
 * @param double price - The current trading price of the stock
 * @param double lowPrice - The lowest price of the stock for the current trading day
 * @param double highPrice - The highest price of the stock for the current trading day
 * @param double previousDay - The closing price of the stock from the previous trading day
 * @param double weekHigh - The highest price the stock reached in the past 52 weeks
 * @param double weekLow - The lowest price the stock reached in the past 52 weeks
 */
stockType::stockType(string stockName, string stockSymbol, double price, double lowPrice, double highPrice, double previousDay, double weekHigh, double weekLow)
{
    setStockName(stockName);
    setSymbol(stockSymbol);
    setCurrentPrice(price);
    setLowPriceOfTheDay(lowPrice);
    setHighPriceOfTheDay(highPrice);
    setPreviousDayClosingPrice(previousDay);
    setFiftyTwoWeeksHigh(weekHigh);
    setFiftyTwoWeeksLow(weekLow);
}