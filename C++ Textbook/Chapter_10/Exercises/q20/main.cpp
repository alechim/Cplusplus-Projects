#include <iostream>
#include <iomanip>
#include "stockType.h"

using namespace std;

int main()
{
    // Class Object Variables
    stockType stock1;
    stockType stock2("Apple Inc.", "AAPL", 189.50, 187.25, 190.75, 185.75, 198.23, 160.45);
    stockType stock3 = stockType("Microsoft Corporation", "MSFT", 410.32, 407.85, 414.50, 405.22, 425.76, 298.55);

    // Use setters to change values in stock1
    stock1.setStockName("Tesla, Inc.");
    stock1.setSymbol("TSLA");
    stock1.setCurrentPrice(237.49);
    stock1.setLowPriceOfTheDay(235.60);
    stock1.setHighPriceOfTheDay(241.75);
    stock1.setPreviousDayClosingPrice(245.20); 
    stock1.setFiftyTwoWeeksHigh(278.98);
    stock1.setFiftyTwoWeeksLow(138.80);

    cout << "+===== Stock Information Demo =====+" << endl;
    cout << "| Stock 1 (Values set using setters):" << endl;
    stock1.print();

    // Calculate and display gain/loss percentage for stock1
    cout << fixed << setprecision(2) << ((stock1.percentGainLoss() < 0) ? "| Percent Loss: " : "| Percent Gain: ") << abs(stock1.percentGainLoss()) << "%" << endl;
    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;

    cout << endl << "+" << setfill('=') << setw(34) << "" << "+" << endl;
    cout << "| Stock 2 (Initialized with constructor):" << endl;
    stock2.print();

    // Calculate and display gain/loss percentage for stock2
    cout << fixed << setprecision(2) << ((stock2.percentGainLoss() < 0) ? "| Percent Loss: " : "| Percent Gain: ") << abs(stock2.percentGainLoss()) << "%" << endl;
    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;

    cout << endl << "+" << setfill('=') << setw(34) << "" << "+" << endl;
    cout << "| Stock 3 (Values set using constructor):" << endl;
    stock3.print();
    cout << "| Using getters - " << stock3.getName() << " (" << stock3.getSymbol() << ") current price: $" << stock3.getCurrentPrice() << endl;

    // Calculate and display gain/loss percentage for stock3
    cout << fixed << setprecision(2) << ((stock3.percentGainLoss() < 0) ? "| Percent Loss: " : "| Percent Gain: ") << abs(stock3.percentGainLoss()) << "%" << endl;
    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;

    // Modify some values and show updates
    cout << endl << "Updating Stock 3 values..." << endl << endl;
    stock3.setCurrentPrice(415.67);
    stock3.setHighPriceOfTheDay(417.90);

    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;
    cout << "| Stock 3 after price update:" << endl;
    stock3.print();
    cout << fixed << setprecision(2) << ((stock3.percentGainLoss() < 0) ? "| Percent Loss: " : "| Percent Gain: ") << abs(stock3.percentGainLoss()) << "%" << endl;
    cout << "+" << setfill('=') << setw(34) << "" << "+" << endl;

    return 0;
}