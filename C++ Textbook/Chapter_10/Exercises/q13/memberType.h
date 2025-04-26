#include <string>

class memberType
{
    public:
        void printMember();
        void setID(std::string);
        void setBooksPurchased(int);
        void setAmountSpent(double);

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
};