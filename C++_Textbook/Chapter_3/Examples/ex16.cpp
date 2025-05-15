// Example 3-16: Movie Tickets Sale and Donation to Charity
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Variables
    string movieName = "";
    double adultTicketPrice = 0.0;
    double childTicketPrice = 0.0;
    int noOfAdultTicketsSold = 0;
    int noOfChildTicketsSold = 0;
    double percentDonation = 0.0;
    double grossAmount = 0.0;
    double amountDonated = 0.0;
    double netSaleAmount = 0.0;

    // Prompt for Input
    cout << fixed << showpoint << setprecision(2);
    cout << "Enter the movie name: ";
    getline(cin, movieName);
    cout << endl;

    cout << "Enter the price of an adult ticket: ";
    cin >> adultTicketPrice;
    cout << endl;

    cout << "Enter the price of a child ticket: ";
    cin >> childTicketPrice;
    cout << endl;

    cout << "Enter the number of adult tickets sold: ";
    cin >> noOfAdultTicketsSold;
    cout << endl;

    cout << "Enter the price of child tickets sold: ";
    cin >> noOfChildTicketsSold;
    cout << endl;

    cout << "Enter the percentage of donation: ";
    cin >> percentDonation;
    cout << endl << endl;

    // Calculations
    grossAmount = adultTicketPrice * noOfAdultTicketsSold + childTicketPrice * noOfChildTicketsSold;
    amountDonated = grossAmount * percentDonation / 100;
    netSaleAmount = grossAmount - amountDonated;

    // Display Results
    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << setfill('.') << left << setw(35) << "Movie Name: " << right << " " << movieName << endl;
    cout << left << setw(35) << "Number of Tickets Sold: " << setfill(' ') << right << setw(10) << noOfAdultTicketsSold + noOfChildTicketsSold << endl;
    cout << setfill('.') << left << setw(35) << "Gross Amount: " << setfill(' ') << right << " $" << setw(8) << grossAmount << endl;
    cout << setfill('.') << left << setw(35) << "Percentage of Gross Amount Donated: " << setfill(' ') << right << setw(9) << percentDonation << '%' << endl;
    cout << setfill('.') << left << setw(35) << "Amount Donated: " << setfill(' ') << right << " $" << setw(8) << amountDonated << endl;
    cout << setfill('.') << left << setw(35) << "Net Sale: " << setfill(' ') << right << " $" << setw(8) << netSaleAmount << endl;

    return 0;
}