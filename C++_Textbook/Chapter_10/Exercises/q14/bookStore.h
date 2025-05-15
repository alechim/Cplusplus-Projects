#ifndef BOOK_STORE_H
#define BOOK_STORE_H

#include <string>

class bookType
{
    public:
        void printBook();

        void setAuthors(std::string = "", std::string = "", std::string = "", std::string = "");
        std::string getAuthors() const;
        void setISBN(std::string);

        // Inline Setters and Getters
        void setTitle(std::string value) { title = value; }
        std::string getTitle() const { return title; }
        void setPublisher(std::string value) { publisher = value; }
        std::string getPublisher() const { return publisher; }
        std::string getISBN() const { return ISBN; }
        void setPrice(double value) { price = value; }
        double getPrice() const { return price; }
        void setCopies(int value) { copies = value; }
        int getCopies() const { return copies; }
        void setYear(int value) { year = value; }
        int getYear() const { return year; }

        // Constructor
        bookType(std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", std::string = "", double = 0.0, int = 0, int = 0);
    private:
        std::string title;
        std::string authors[4];
        int noOfAuthors;
        std::string publisher;
        std::string ISBN;
        double price;
        int copies;
        int year;
};

class memberType
{
    public:
        void printMember();

        void setID(std::string);
        void setBooksPurchased(int);
        void setAmountSpent(double);

        void addPurchase(double);
        double getAveragePrices() const;
        void resetPriceTracking();

        // Inline Setters and Getters
        void setName(std::string value) { name = value; }
        std::string getName() const { return name; }
        std::string getID() const { return ID; }
        int getBooksPurchased() const { return booksPurchased; }
        double getAmountSpent() const { return amountSpent; }

        memberType(std::string = "", std::string = "", int = 0, double = 0.0);
    private:
        std::string name;
        std::string ID;
        int booksPurchased;
        double amountSpent;
        double lastTenPrices[10];
        int priceIndex;
};

#endif