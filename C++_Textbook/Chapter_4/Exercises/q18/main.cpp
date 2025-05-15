// Question 18: Calculate Body Fat
/**
 * Given:
 * - Body fat formula for women and men
 * Personal Note:
 * - I don't think this program works as intended due to the provided formulas but this program 
 * is a solution to the given exercise question.
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Variables
    string gender = "";
    double bodyWeight = 0.0;
    double wristMeasure = 0.0;
    double bodyFat = 0.0;
    double bodyFatPercent = 0.0;

    // Prompt for Input
    do
    {
        cout << "Please enter your gender (male/female): ";
        cin >> gender;
        if(cin.fail() || (gender != "male" && gender != "female"))
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter either 'male' or 'female'." << endl;
        } else
            break;
    } while(true);
    
    if(gender == "male")
    {
        // Prompt for Input
        do
        {
            cout << "Enter your body weight: ";
            cin >> bodyWeight;
            if(cin.fail() || bodyWeight <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
                continue;
            } 

            cout << "Enter your wrist measurement: ";
            cin >> wristMeasure;
            if(cin.fail() || wristMeasure <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            } else
                break;
        } while(true);
        
        // Calculations
        double A1 = (bodyWeight * 1.082) + 94.42;
        double A2 = wristMeasure * 4.15;
        double B = A1 - A2;
        bodyFat = bodyWeight - B;
        bodyFatPercent = bodyFat * 100 / bodyWeight;
    } else if(gender == "female")
    {
        // Variables
        double waistMeasure = 0.0;
        double hipMeasure = 0.0;
        double forearmMeasure = 0.0;

        // Prompt for Input
        do
        {
            cout << "Enter your body weight: ";
            cin >> bodyWeight;
            if(cin.fail() || bodyWeight <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
                continue;
            } 

            cout << "Enter your wrist measurement at the fullest point: ";
            cin >> wristMeasure;
            if(cin.fail() || wristMeasure <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
                continue;
            } 

            cout << "Enter your waist measurement at your navel: ";
            cin >> waistMeasure;
            if(cin.fail() || waistMeasure <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
                continue;
            } 

            cout << "Enter your hip measurement at the fullest point: ";
            cin >> hipMeasure;
            if(cin.fail() || hipMeasure <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
                continue;
            } 

            cout << "Enter your forearm measurement at the fullest point: ";
            cin >> forearmMeasure;
            if(cin.fail() || forearmMeasure <= 0.0)
            {
                cin.clear();
                cin.ignore(40, '\n');
                cout << "Invalid Input! Please enter a non-zero positive double value." << endl;
            } else
                break;
        } while(true);

        // Calculations
        double A1 = (bodyWeight * 0.732) + 8.987;
        double A2 = wristMeasure / 3.140;
        double A3 = waistMeasure * 0.157;
        double A4 = hipMeasure * 0.249;
        double A5 = forearmMeasure * 0.434;
        double B = A1 + A2 - A3 - A4 + A5;
        bodyFat = bodyWeight - B;
        bodyFatPercent = bodyFat * 100 / bodyWeight;
    }

    // Display Results
    cout << fixed << setprecision(2);
    cout << "Your body fat is " << bodyFat << "." << endl;
    cout << "Your body fat percentage is " << bodyFatPercent << "." << endl;

    return 0;
}