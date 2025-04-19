#ifndef STUDENT_TYPE_H
#define STUDENT_TYPE_H

#include <string>

class studentType
{
    public: 
        void calculateGrade();
        void findHighestScore();
        void setStudentName(std::string, std::string);
        void setTestScore(int);
        std::string getFirstName();
        std::string getLastName();
        int getTestScore();
        char getGrade();
        static int getTopScore();
        studentType();
    private:
        std::string studentFName;
        std::string studentLName;
        int testScore;
        char grade;
        static int topScore;
};

#endif