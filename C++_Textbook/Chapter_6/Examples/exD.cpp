// Exercise 6-D: Comparison of Class Averages
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// ***Function Prototypes***
void calculateAverage(ifstream& inp, double& courseAvg);
void printResult(ofstream& outp, string courseID, int groupNo, double avg);
void printHeading(ofstream& outp);

int main()
{
    // Variables
    string courseId1 = "";      // Course ID for group 1
    string courseId2 = "";      // Course ID for group 2
    int numberOfCourses = 0;    
    double avg1 = 0.0;          // Average for a course in group 1  
    double avg2 = 0.0;          // Average for a course in group 2
    double avgGroup1 = 0.0;     // Average group 1
    double avgGroup2 = 0.0;     // Average group 2
    ifstream group1;            // Input stream variable for group 1
    ifstream group2;            // Input stream variable for group 2
    ofstream outfile;           // Output stream variable

    // Open input files
    group1.open("group1.txt");
    group2.open("group2.txt");
    if(!group1 || !group2)
    {
        cout << "Unable to open files." << endl;
        cout << "Program terminates." << endl;
        return 1;
    }

    outfile.open("student.out");
    outfile << fixed << showpoint << setprecision(2);

    printHeading(outfile); 

    group1 >> courseId1;
    group2 >> courseId2;

    while(group1 && group2)
    {
        if(courseId1 != courseId2)
        {
            cout << "Data error: Course IDs do not match." << endl;
            cout << "Program terminates." << endl;
            return 1;
        } else
        {
            calculateAverage(group1, avg1);
            calculateAverage(group2, avg2);
            printResult(outfile, courseId1, 1, avg1);
            printResult(outfile, courseId2, 2, avg2);
            avgGroup1 += avg1;
            avgGroup2 += avg2;
            numberOfCourses++;
        }
        group1 >> courseId1;
        group2 >> courseId2;
    }

    if(group1 && !group2)
        cout << "Ran out of data for group 2 before group 1." << endl;
    else if(!group1 && group2)
        cout << "Ran out of data for group 1 before group 2." << endl;
    else
    {
        outfile << "\nGroup 1 -- ****\n";
        outfile << "Group 2 -- ####\n\n";
        outfile << "Avg for group 1: " << avgGroup1 / numberOfCourses << endl;
        outfile << "Avg for group 2: " << avgGroup2 / numberOfCourses << endl;
    }

    // Close the files
    group1.close();
    group2.close();
    outfile.close();

    return 0;
}

// ***Functions***
void calculateAverage(ifstream &inp, double& courseAvg)
{
    // Variables
    double totalScore = 0.0;
    int numberOfStudents = 0;
    int score = 0;

    inp >> score;
    while(score != -999)
    {
        totalScore += score;
        numberOfStudents++;
        inp >> score;
    }

    courseAvg = totalScore / numberOfStudents;
}

void printResult(ofstream &outp, string courseID, int groupNo, double avg)
{
    // Variables
    int noOfSymbols = 0;
    int count = 0;

    if(groupNo == 1)
        outp << setw(4) << courseID << "    ";
    else
        outp << "        ";
    
    noOfSymbols = static_cast<int>(avg) / 2;

    if(groupNo == 1)
        for(count = 1; count <= noOfSymbols; count++)
            outp << "*";
    else   
        for(count = 1; count <= noOfSymbols; count++)
            outp << "#";
    outp << endl;
}

void printHeading(ofstream& outp)
{
    outp << "Course         Course Average" << endl;
    outp << "  ID    0   10   20   30   40   50   60   70   80   90   100" << endl;
    outp << "        |....|....|....|....|....|....|....|....|....|....|" << endl;
}