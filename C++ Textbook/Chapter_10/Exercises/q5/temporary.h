#include <string>

class temporary
{
    public:
        void set(std::string, double, double);
        void print();
        double manipulate();
        void get(std::string&, double&, double&);
        void setDescription(std::string);
        void setFirst(double);
        void setSecond(double);
        std::string getDescription() const;
        double getFirst() const;
        double getSecond() const;

        temporary(std::string = "", double = 0.0, double = 0.0);
    private:
        std::string description;
        double first;
        double second;
};