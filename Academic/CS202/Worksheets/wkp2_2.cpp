#include <iostream>
#include <iomanip>

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
void displayEmployees(Employee[], int);

int main()
{
    // Variables
    int listSize = 4;
    Employee employeeList[listSize];

    // Prompt for Input
    cout << "+==========================+" << endl;
    for (int i = 0; i < listSize; i++)
    {
        cout << "| Enter Person " << (i+1) << "'s Details -" << endl;
        cout << "| Enter Name: ";
        getline(cin, employeeList[i].name);
    
        cout << "| Enter Age: ";
        cin >> employeeList[i].age;
        cin.ignore(40, '\n');
    
        cout << "| Enter Role: ";
        getline(cin, employeeList[i].role);
    
        cout << "| Enter Salary: $";
        cin >> employeeList[i].salary;
        cin.ignore(40, '\n');
    
        cout << "| Enter Department: ";
        getline(cin, employeeList[i].department);
        cout << "+--------------------------+" << endl;
    }
    
    // Display Results
    displayEmployees(employeeList, listSize);

    return 0;
}

// Function Definition
void displayEmployees(Employee employeeList[], int size)
{
    cout << "\n+==========================+" << endl;
    cout << "| The Employee Data List" << endl;
    for(int i = 0; i < size; i++)
    {
        cout << "+==========================+" << endl;
        cout << left << setw(14) << "| Name: " << employeeList[i].name << endl;
        cout << left << setw(14) << "| Age: " << employeeList[i].age << endl;
        cout << left << setw(14) << "| Role: " << employeeList[i].role << endl;
        cout << left << setw(14) << fixed << showpoint << setprecision(2) << "| Salary: " << "$" << employeeList[i].salary << endl;
        cout << left << setw(13) << "| Department: " << employeeList[i].department << endl;
    }
    cout << "+==========================+" << endl;
}