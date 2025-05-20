#include <iomanip>
#include "courseType.h"

using namespace std;

void courseType::setCourseInfo(string cName, string cNo, int credits)
{
    courseName = cName;
    courseNo = cNo;
    courseCredits = credits;
}

void courseType::print(ostream& outF)
{
    outF << left;
    outF << setw(8) << courseNo << "    ";
    outF << setw(15) << courseName;
    outF << right;
    outF << setw(3) << courseCredits << "   ";
}

// Inline Getter Functions
int courseType::getCredits() { return courseCredits; }
string courseType::getCourseNumber() { return courseNo; }
string courseType::getCourseName() { return courseName; }

courseType::courseType(string cName, string cNo, int credits)
{
    courseName = cName;
    courseNo = cNo;
    courseCredits = credits;
}