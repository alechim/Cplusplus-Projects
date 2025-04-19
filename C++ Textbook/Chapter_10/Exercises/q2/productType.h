#ifndef PRODUCT_TYPE_H
#define PRODUCT_TYPE_H

#include <string>

class productType
{
    public:
        productType();
        productType(int, double, double);
        productType(std::string, int, double, double);
        productType(std::string, std::string, std::string, int, double, double);

        void set(std::string, std::string, std::string, int, double, double);
        void print() const;

        void setQuantitiesInStock(int x);
        void updateQuantitiesInStock(int x);
        int getQuantitiesInStock() const;

        void setPrice(double x);
        double getPrice() const;
        void setDiscount(double d);
        double getDiscount() const;

    private:
        std::string productName;
        std::string id;
        std::string manufacturer;
        int quantitiesInStock;
        double price;
        double discount;
};

#endif