#include <string>

class houseType
{
    public:
        void set(std::string, int, int, int, int, int, double, double);
        void print() const;
        void setStyle(std::string);
        std::string getStyle() const;
        void setNumOfBedrooms(int);
        int getNumOfBedrooms() const;
        void setNumOfBathrooms(int);
        int getNumOfBathrooms() const;
        void setNumOfCarsGarage(int);
        int getNumOfCarsGarage() const;
        void setYearBuilt(int);
        int getYearBuilt() const;
        void setFinishedSquareFootage(int);
        int getFinishedSquareFootage() const;
        void setPrice(double);
        double getPrice() const;
        void setTax(double);
        double getTax() const;

        houseType(std::string = "", int = 0, int = 0, int = 0, int = 0, int = 0, double = 0, double = 0);
    
    private:
        std::string style;
        int numOfBedrooms;
        int numOfBathrooms;
        int numOfCarsGarage;
        int yearBuilt;
        int finishedSquareFootage;
        double price;
        double tax;
};