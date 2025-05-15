#include <string>

class bankAccount
{
    public:
        void printAccount();

        // Inline Setters and Getters
        void setAccountName(std::string value) { accountName = value; }
        void setAccountType(std::string value) { accountType = value; }
        void setAccountBalance(double value) { accountBalance = value; }
        void setInterestRate(double value) { interestRate = value; }

        bankAccount(std::string = "", std::string = "", double = 0.0, double = 0.0);
    private:
        std::string accountName;
        int accountNumber;
        std::string accountType;        // Checking or Saving
        double accountBalance;
        double interestRate;

        static int nextAccountNumber;
};