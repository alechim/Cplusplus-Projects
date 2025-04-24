#include <string>

class personType
{
    public:
        void print() const;
        void setName(std::string first, std::string middle, std::string last);
        bool checkFirstName(const personType&);
        bool checkLastName(const personType&);

        // Inline Setters and Getters
        void setFirstName(std::string first) { firstName = first; }
        void setMiddleName(std::string middle) { middleName = middle; }
        void setLastName(std::string last) { lastName = last; }
        std::string getFirstName() const { return firstName; }
        std::string getMiddleName() const { return middleName; }
        std::string getLastName() const { return lastName; }

        personType(std::string first = "", std::string middle = "", std::string last = "");
    private:
        std::string firstName;       // Variable to store the first name
        std::string middleName;      // Variable to store the middle name
        std::string lastName;        // Variable to store the last name
};