#include <string> 

class dayType
{
    public:
        void printDay();
        void addDays(int);
        void setDay(std::string);
        std::string getDay();
        std::string getPreviousDay();
        std::string getNextDay();

        dayType(std::string = "Sunday");

    private:
        int index = 0;
        const std::string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
};