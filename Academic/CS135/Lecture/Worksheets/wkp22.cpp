#include <iostream>

using namespace std;

int main()
{
    const int NUM_STUDENT = 3;
    struct studentType
    {
        string firstName = "";
        string lastName = "";
        int courseGrade = 0;
        int courseSection = 0;
        double gpa = 0.0;
    };
    studentType students[NUM_STUDENT];

    for (int i = 0; i < NUM_STUDENT; i++)
    {
        cout << "Enter First, Last, Grade, Section, GPA: ";
        cin >> students[i].firstName >> students[i].lastName >> students[i].courseGrade >> students[i].courseSection >> students[i].gpa;
    }

    for (int c = 0; c < NUM_STUDENT; c++)
        cout << "Student " << c << " " << students[c].firstName << " " << students[c].lastName << " " << students[c].courseGrade << " " << students[c].courseSection << " " << students[c].gpa << endl;

    return 0;
}
