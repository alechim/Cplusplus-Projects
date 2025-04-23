/**
 * Alec Him, 2001543593, CS202 1004, Assignment 2
 * Description: Space Rocket Ticket Booking System
 * Input: Rocket selection, passenger details, seat numbers
 * Output: Ticket prices, rocket specifications, travel details
 */
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

// -===================================-
// | Classes
class passenger
{
    public: 
        void setName(string first, string last);    // First Name + Last Name
        string getName() const;                     // Return Name
        void setPassengerType(string);              // Set Veteran or Non-veteran from the passenger choice
    private:
        string Name;            // Variable to store the name
        string passengerType;   // Variable to store Veteran or Non-veteran
};

class rocket
{
    public:
        void setSeats(int);             // from rocket admin
        int getSeats() const;           // for passenger reference

        void setTicketPrice(int);       // from rocket admin
        int getTicketPrice() const;     // for passenger reference

        int checkRocketAvailability();  // check rocket availability for the passengers selection
        void setRocketType(string);     // cold-gas, chemical, thermoelectric, hybrid

        void purchaseTicket();          // reserve seats for all selected passengers
        int getBookedSeats() const;     // show the reserved/booked seats of each rocket

        void setVelocity(double);       // set velocity
        double getVelocity() const;     // get velocity

        void setFuelCapacity(int);      // set fuel capacity

        void setRocketSpecs(string, double, double);    // set rocket specifications
        void getRocketSpecs() const;                    // get rocket specifications

        void setTimeReq(double);        // destination reaching time - travel distance/velocity;
                                        // travelDistance = 238855
        double getTimeReq() const;

        rocket();       // constructor for initializing bookedSeat = 0 (private member variable)
    private:
        int ticketPrice;
        string rocketType;
        int seats;
        double timeReq;
        int bookedSeats;

        // Rocket Specifications
        string propellant;
        double acceleration;
        double velocity;
        double fuelCapacity;
        double thrust;
};

class Menu
{
    public:
        Menu(string);
        int showRocketMenu();
    private:
        int choice;
};
// -===================================-

// Function Prototypes
void promptInput(int&, const string);

int main()
{
    // Variables
    int pSize = 0;
    double travelDistance = 238855;     // distance from earth to moon
    double totalPrice = 0.0;            // price with no discount
    double discount = 0.0;              // price discount for veteran 10%
    double toPay = 0.0;                 // final price after discount
    int choice = 0;                     // choice selection from rocket menu
    int seats = 0;                      // selection of number of seats - basically to set seats from admin
    char ch = ' ';                      // for yes/no option to get more tickets
    double remainingDistance = 0.0;     // to store the remaining distance
    string firstName = "", lastName = "";
    int pType = 0;
    double time = 0.0;
    
    // Variables - Rocket Class Objects
    rocket cgRocket, cRocket, tRocket, hRocket;

    // ------------------------------------
    // Admin Terminal
    Menu menu("Welcome Admin- Set seats to \n YOU CAN FLY TO SPACE");

    // Set the amount of seats available in each rocket
    promptInput(seats, "Enter number of seats in Cold-Gas Rocket : ");
    cgRocket.setSeats(seats);
    
    seats = 0;
    promptInput(seats, "Enter number of seats in Chemical Rocket : ");
    cRocket.setSeats(seats);
    
    seats = 0;
    promptInput(seats, "Enter number of seats in Thermoelectric Rocket : ");
    tRocket.setSeats(seats);

    seats = 0;
    promptInput(seats, "Enter number of seats in Hybrid Rocket : ");
    hRocket.setSeats(seats);

    // ------------------------------------
    // Passenger Terminal
    do
    {
        Menu("Welcome to YOU CAN FLY TO SPACE!");

        // Display Availability of Seats
        cout << "Status of seats availability: " << endl;
        cout << "Cold-Gas Rocket is available with: " << cgRocket.checkRocketAvailability() << " Passengers" << endl;
        cout << "Chemical Rocket is available with: " << cRocket.checkRocketAvailability() << " Passengers" << endl;
        cout << "Thermoelectric Rocket is available with: " << tRocket.checkRocketAvailability() << " Passengers" << endl;
        cout << "Hybrid Rocket is available with: " << hRocket.checkRocketAvailability() << " Passengers" << endl;

        // Tests whether or not the seats are available or not and reprompts user if there is no more space
        do
        {
            choice = menu.showRocketMenu();

            cout << "Checking seat availability..." << endl;
            if(cgRocket.checkRocketAvailability() == 0 && choice == 1)
                cout << "The Cold-Gas Rocket is unavailable" << endl;
            else if(cRocket.checkRocketAvailability() == 0 && choice == 2)
                cout << "The Chemical Rocket is unavailable" << endl;
            else if(tRocket.checkRocketAvailability() == 0 && choice == 3)
                cout << "The Thermoelectric Rocket is unavailable" << endl;
            else if(cgRocket.checkRocketAvailability() == 0 && choice == 4)
                cout << "The Hybrid Rocket is unavailable" << endl;
            else
                break;
        } while(true);

        // Based on choice, sets the seat availability to the selected seat availability
        switch(choice)
        {
            case 1:
                seats = cgRocket.checkRocketAvailability();
                cgRocket.setRocketType("Cold-Gas");
                cgRocket.setTicketPrice(10000);
                toPay = cgRocket.getTicketPrice();
                cgRocket.setRocketSpecs("Hydrogen", 12.9, 12.1);
                cgRocket.setFuelCapacity(773000);
                cgRocket.setVelocity(25000);
                cgRocket.setTimeReq(ceil(travelDistance / cgRocket.getVelocity()));
                break;
            case 2:
                seats = cRocket.checkRocketAvailability();
                cRocket.setRocketType("Chemical");
                cRocket.setTicketPrice(12000);
                toPay = cRocket.getTicketPrice();
                cRocket.setRocketSpecs("Hypergolic", 12.1, 12.2);
                cRocket.setFuelCapacity(759320);
                cRocket.setVelocity(21000);
                cRocket.setTimeReq(ceil(travelDistance / cRocket.getVelocity()));
                break;
            case 3:
                seats = tRocket.checkRocketAvailability();
                tRocket.setRocketType("Thermoelectric");
                tRocket.setTicketPrice(15000);
                toPay = tRocket.getTicketPrice();
                tRocket.setRocketSpecs("Hydrazine", 38.1, 15.1);
                tRocket.setFuelCapacity(657200);
                tRocket.setVelocity(23000);
                tRocket.setTimeReq(ceil(travelDistance / tRocket.getVelocity()));
                break;
            case 4:
                seats = hRocket.checkRocketAvailability();
                hRocket.setRocketType("Hybrid");
                hRocket.setTicketPrice(16000);
                toPay = hRocket.getTicketPrice();
                hRocket.setRocketSpecs("Oxidizers", 90.2, 35.1);
                hRocket.setFuelCapacity(521400);
                hRocket.setVelocity(28000);
                hRocket.setTimeReq(ceil(travelDistance / hRocket.getVelocity()));
                break;
        }

        // Displays how many seats are available to book and loops until input is correct
        do
        {
            cout << "Available seats are : " << seats << endl;
            cout << "Enter number of tickets [Between the range of 1 - " << seats << "] : ";
            cin >> pSize;

            if(cin.fail() || pSize < 1 || pSize > seats)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Error - Input is not within parameters. Please try again." << endl;
            } else
                break;
        } while(true);

        passenger psg[pSize];
        // Loops until all Passengers previously inputted have been reserved
        for(int i = 0; i < pSize; i++)
        {
            // Display Prompt for Name
            cout << "---------------------------------" << endl;
            cout << "Enter details of Passenger " << i + 1 << endl;
            cout << "---------------------------------" << endl;
            cout << "Enter your First Name: ";
            cin >> firstName;

            cout << "Enter your Last Name: ";
            cin >> lastName;
            cout << "---------------------------------" << endl;
            cout << "<= Saving Passenger =>" << endl << endl;
            
            psg[i].setName(firstName, lastName);

            // Display Prompt for Passenger Type
            cout << "---------------------------------" << endl;
            cout << "   | Select your passenger type" << endl;
            cout << "---------------------------------" << endl;
            cout << "1. | Veteran" << endl;
            cout << "2. | Nonveteran" << endl << endl;

            // Reads User input for Passenger type and continues to prompt if Input is not within range
            do
            {
                cout << "Enter your selection : ";
                cin >> pType;
                if(cin.fail() || (pType != 1 && pType != 2))
                {
                    cin.clear();
                    cin.ignore(40, '\n');
                    cout << "Error - Incorrect Selection. Please Try Again." << endl;
                } else
                    break;
            } while(true);
            
            // Calculates the price based on previous input
            switch(pType)
            {
                case 1:
                    psg[i].setPassengerType("Veteran");
                    discount = toPay * 0.10;
                    totalPrice = toPay - discount;
                    cout << fixed << showpoint << setprecision(2);
                    cout << "Your ticket price with 10% discount is $" << totalPrice << endl;
                    break;
                case 2:
                    psg[i].setPassengerType("Non-Veteran");
                    totalPrice = toPay;
                    cout << fixed << showpoint << setprecision(2);
                    cout << "Your ticket price is $" << totalPrice << endl;
            }

            // Displays that Inputted User Name has successfully reserved seats
            cout << "\nDear " << psg[i].getName() << " - your seat is reserved successfully" << endl;
        }

        // Subtracts the seat selection from tickets to "reserve" the seats
        switch(choice)
        {
            case 1:
                cgRocket.setSeats(seats);
                cgRocket.getRocketSpecs();
                break;
            case 2:
                cRocket.setSeats(seats);
                cRocket.getRocketSpecs();
                break;
            case 3:
                tRocket.setSeats(seats);
                tRocket.getRocketSpecs();
                break;
            case 4:
                hRocket.setSeats(seats);
                hRocket.getRocketSpecs();
        }

        // Prompts user whether or not to reserve any other seats
        do
        {
            cout << "Do you want to book more seats? (y/n) : ";
            cin >> ch;
            cout << endl;
        
            if(cin.fail() || (ch != 'y' && ch != 'n'))
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter 'y' or 'n' to continue." << endl;
            } else
                break;
        } while(true);
        
        if(ch == 'n')
            break;
    } while(true);
    
    // ------------------------------------
    // Display Booked Seats & Travelling Distance
    cout << fixed << noshowpoint << setprecision(0);
    if(cgRocket.getBookedSeats() != 0)
    {
        cout << "Booked seats for Cold-Gas Rocket: " << cgRocket.getBookedSeats() << endl;
        for(time = 1; time <= cgRocket.getTimeReq(); time++)
        {
            double currentDistance = (cgRocket.getVelocity() < (travelDistance - remainingDistance)) ? cgRocket.getVelocity() : (travelDistance - remainingDistance);
            remainingDistance += currentDistance;

            cout << endl << "--------------------------------" << endl;
            cout << "Dear Cold-Gas Rocket passengers..." << endl;
            cout << "--------------------------------" << endl;
            cout << "Distance travelled after " << time << " hours is " << currentDistance << " miles" << endl;
            cout << "Remaining distance is " << (travelDistance - remainingDistance) << " miles" << endl;
        }
        cout << endl << "--------------------------------" << endl;
        cout << "Dear Cold-Gas Rocket passengers, we are landing on destination" << endl << endl;
    }
    if(cRocket.getBookedSeats() != 0)
    {
        cout << "Booked seats for Chemical Rocket: " << cRocket.getBookedSeats() << endl;
        for(time = 1; time <= cRocket.getTimeReq(); time++)
        {
            double currentDistance = (cRocket.getVelocity() < (travelDistance - remainingDistance)) ? cRocket.getVelocity() : (travelDistance - remainingDistance);
            remainingDistance += currentDistance;

            cout << endl << "--------------------------------" << endl;
            cout << "Dear Chemical Rocket passengers..." << endl;
            cout << "--------------------------------" << endl;
            cout << "Distance travelled after " << time << " hours is " << remainingDistance << " miles" << endl;
            cout << "Remaining distance is " << (travelDistance - remainingDistance) << " miles" << endl;
        }
        cout << endl << "--------------------------------" << endl;
        cout << "Dear Chemical Rocket passengers, we are landing on destination" << endl << endl;
    }
    if(tRocket.getBookedSeats() != 0)
    {
        cout << "Booked seats for Thermoelectric Rocket: " << tRocket.getBookedSeats() << endl;
        for(time = 1; time <= tRocket.getTimeReq(); time++)
        {
            double currentDistance = (tRocket.getVelocity() < (travelDistance - remainingDistance)) ? tRocket.getVelocity() : (travelDistance - remainingDistance);
            remainingDistance += currentDistance;

            cout << endl << "--------------------------------" << endl;
            cout << "Dear Thermoelectric Rocket passengers..." << endl;
            cout << "--------------------------------" << endl;
            cout << "Distance travelled after " << time << " hours is " << currentDistance << " miles" << endl;
            cout << "Remaining distance is " << (travelDistance - remainingDistance) << " miles" << endl;
        }
        cout << endl << "--------------------------------" << endl;
        cout << "Dear Thermoelectric Rocket passengers, we are landing on destination" << endl << endl;
    }
    if(hRocket.getBookedSeats() != 0)
    {
        cout << "Booked seats for Hybrid Rocket: " << hRocket.getBookedSeats() << endl;
        for(time = 1; time <= hRocket.getTimeReq(); time++)
        {
            double currentDistance = (hRocket.getVelocity() < (travelDistance - remainingDistance)) ? hRocket.getVelocity() : (travelDistance - remainingDistance);
            remainingDistance += currentDistance;

            cout << endl << "--------------------------------" << endl;
            cout << "Dear Hybrid Rocket passengers..." << endl;
            cout << "--------------------------------" << endl;
            cout << "Distance travelled after " << time << " hours is " << currentDistance << " miles" << endl;
            cout << "Remaining distance is " << (travelDistance - remainingDistance) << " miles" << endl;
        }
        cout << endl << "--------------------------------" << endl;
        cout << "Dear Hybrid Rocket passengers, we are landing on destination" << endl << endl;
    }
    
    return 0;
}

// Function Defintions
void promptInput(int& value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value < 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a positive integer value." << endl;
        } else
            break;
    } while(true);
}

// -===================================-
// | Class Function Definitions - Rocket
rocket::rocket() 
{ 
    seats = 0;
    bookedSeats = 0; 
}

int rocket::checkRocketAvailability() { return seats - bookedSeats; }

// | == Getters and Setters == |
void rocket::setSeats(int newSeats) 
{ 
    if(seats == 0)
        seats = newSeats;
    else if(seats < newSeats)
        cout << "There are not enough seats available." << endl;
    else
        bookedSeats = bookedSeats + newSeats;
}
int rocket::getSeats() const { return seats; }
int rocket::getBookedSeats() const { return bookedSeats; }

void rocket::setTicketPrice(int newTicketPrice) { ticketPrice = newTicketPrice; }
int rocket::getTicketPrice() const { return ticketPrice; }

void rocket::setRocketType(string newType) { rocketType = newType; }

void rocket::setVelocity(double newVelocity) { velocity = newVelocity; }
double rocket::getVelocity() const { return velocity; }

void rocket::setFuelCapacity(int newCapacity) { fuelCapacity = newCapacity; }

void rocket::setTimeReq(double newReq) { timeReq = newReq; }
double rocket::getTimeReq() const { return timeReq; }

void rocket::setRocketSpecs(string newProp, double newAccel, double newThrust)
{
    propellant = newProp;
    acceleration = newAccel;
    thrust = newThrust;
}

void rocket::getRocketSpecs() const
{
    cout << "---------------------------------" << endl;
    cout << "Your Rocket Specs : " << endl;
    cout << "---------------------------------" << endl;
    cout << "Propellant Type: " << propellant << endl;
    cout << "Acceleration: " << acceleration << " m/s^2" << endl;
    cout << "Thrust: " << thrust << " Newtons" << endl;
    cout << "Fuel Capacity: " << fuelCapacity << " gallons" << endl;
    cout << "Velocity: " << velocity << " mph" << endl << endl;
}

// -===================================-
// | Class Function Definitions - Menu
Menu::Menu(string msg)
{
    cout << endl << endl;
    cout << "********************************" << endl;
    cout << msg << endl;
    cout << "********************************" << endl << endl;
}

int Menu::showRocketMenu()
{
    int select = 0;

    // Rocket Menu Prompt
    cout << "------------------------------------------------------" << endl;
    cout << "   | Please select a rocket                        |  " << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "1. | Cold Gas and the ticket price is $10000       |  " << endl;
    cout << "2. | Chemical and the ticket price is $12000       |  " << endl;
    cout << "3. | Thermoelectric and the ticket price is $15000 |  " << endl;
    cout << "4. | Hybrid and the ticket price is $16000         |  " << endl;
    cout << "------------------------------------------------------" << endl;

    // Prompt and Validate User Input
    do
    {
        cout << "Please make a selection: ";
        cin >> select;

        if(cin.fail() || select < 1 || select > 4)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a valid choice (1-4)." << endl;
        } else
            break;
    } while(true);

    cout << "<===============================>" << endl;
    switch(select)
    {
        case 1:
            cout << "You have chosen - Cold Gas Rocket" << endl;
            cout << "The price is: $10000" << endl;
            break;
        case 2:
            cout << "You have chosen - Chemical Rocket" << endl;
            cout << "The price is: $12000" << endl;
            break;
        case 3:
            cout << "You have chosen - Thermoelectric Rocket" << endl;
            cout << "The price is: $15000" << endl;
            break;
        case 4:
            cout << "You have chosen - Hybrid Rocket" << endl;
            cout << "The price is: $16000" << endl;
            break;
    }
    cout << "<===============================>" << endl;

    return select;
}

// -===================================-
// | Class Function Defintions - Passenger
void passenger::setName(string first, string last) { Name = first + " " + last; }
string passenger::getName() const { return Name; }
void passenger::setPassengerType(string newType) { passengerType = newType; }