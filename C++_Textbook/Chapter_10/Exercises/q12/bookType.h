#ifndef BOOK_TYPE_H
#define BOOK_TYPE_H

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

#endif