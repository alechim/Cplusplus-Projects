#include <string>

class romanType
{
    public:
        void convertNumeral();
        void setNumeral(std::string);
        std::string getNumeral();
        int getNumericValue();
        romanType(std::string = "");

    private:
        std::string numeral;
        int numericValue;
};