/** 
 * Alec Him, 2001543593, CS135 1009, Lab 6
 * Description: Calculates Max, Min, Sum, Average and Range from a list
 * Input: ./a.out < input6.txt OR Get-Content input6.txt | ./a.out
 * Output: Max, Min, Sum, Average, and Range 
 */
#include <iostream>

using namespace std;

int main()
{
    // Variables
    int max = 0;
    int min = 1000;
    double sum = 0.0;
    double average = 0.0;
    int range = 0;
    double count = 0.0;
    int n = 0;

    cin >> n;

    while(cin)
    {
        sum += n;
        if(max < n)
            max = n;
        if(min > n)
            min = n;
        count++;
        cin >> n;
    }

    // Calculate Average, Range(Max-Min), and Output Answers
    average = sum / count;
    range = max - min;
    
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout << "Range: " << range << endl;

    return 0;
}