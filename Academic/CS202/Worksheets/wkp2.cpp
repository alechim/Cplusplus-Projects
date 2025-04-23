#include <iostream>

using namespace std;

// Struct containing basic information on an Employee
struct Employee
{
    string name;
    int age;
    string role;
    double salary;
    string department;
};

// Function Prototype
void fileInput(int, Employee[]);

int main()
{
    // Variables
    Employee employeeList[10];
    int count = 0;

    // Sets Limit on how many times the User is Prompted
    cout << "How many employees are there?: ";
    cin >> count;
    cout << "--------------------" << endl;

    fileInput(count, employeeList);

    // Displays Array Information
    for (int i = 0; i < count; i++)
    {
        cout << "Name       | " << employeeList[i].name << endl;
        cout << "Age        | " << employeeList[i].age << endl;
        cout << "Role       | " << employeeList[i].role << endl;
        cout << "Salary     | " << employeeList[i].salary << endl;
        cout << "Department | " << employeeList[i].department << endl;
        cout << "--------------------" << endl;
    }
    
    return 0;
}

// Function Definition
void fileInput(int count, Employee employeeList[])
{
    string firstName = "", lastName = "";

    for (int i = 0; i < count; i++)
    {
        cout << "Enter First Name: ";
        cin >> firstName >> lastName;

        employeeList[i].name = firstName + " " + lastName;
        firstName = "";
        lastName = "";
    
        cout << "Enter Age: ";
        cin >> employeeList[i].age;
    
        cout << "Enter Role: ";
        cin >> employeeList[i].role;
    
        cout << "Enter Salary: ";
        cin >> employeeList[i].salary;
    
        cout << "Enter Department: ";
        cin >> employeeList[i].department;
    
        cout << "--------------------" << endl;
    }
}