#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

void promptInput(int &value, const string prompt);
double maximumVolume(int area, int& length, int& width, double& side);

int main()
{
    int area = 0;
    double maxVolume = 0.0;
    int length = 0;
    int width = 0;
    double height = 0;

    promptInput(area, "Enter the area of the cardboard box (inches^2): ");
    maxVolume = maximumVolume(area, length, width, height);
    if(maxVolume == 0.0)
    {
        cout << "The max volume cannot be determined." << endl;
    } else
    {
        cout << fixed << showpoint << setprecision(3);
        cout << "Area: " << area << (area == 1 ? " inch^2." : " inches^2.") << endl;
        cout << "Length: " << length << (length == 1 ? " inch." : " inches.") << endl;
        cout << "Width: " << width << (width == 1 ? " inch." : " inches.") << endl;
        cout << "Height: " << height << (height == 1 ? " inch." : " inches.") << endl; 
        cout << "Maximum Volume: " << maxVolume << (width == 1 ? " inch^3" : " inches^3.") << endl;
    }
    
    return 0;
}

void promptInput(int &value, const string prompt)
{
    do
    {
        cout << prompt;
        cin >> value;
        if(cin.fail() || value <= 0)
        {
            cin.clear();
            cin.ignore(40, '\n');
            cout << "Invalid Input! Please enter a non-zero positive integer value." << endl;
        } else
            break;
    } while(true);
}

double maximumVolume(int area, int& length, int& width, double& side)
{
    double maxVolume = 0.0;
    double volume = 0.0;
    int l = 0;
    int w = 0;
    double x = 0.0;

    // Iterate over factor pairs of the area
    for(int i = 1; i <= round(sqrt(static_cast<double>(area))); i++)
    {
        // Find factor pairs
        if(area % i != 0)
            continue;
        
        l = i;
        w = area / i;

        // Test possible x values from 0 to min(l, w) / 2
        for(x = 0; x <= min(l, w) / 2.0; x += 0.1)
        {
            double y = l - 2 * x;
            double z = w - 2 * x;

            if(y < 0.0 || z < 0.0)
                continue;  // Skip invalid dimensions
            
            volume = x * y * z;
            if(volume > maxVolume)
            {
                maxVolume = volume;
                length = l;
                width = w;
                side = x;
            }
        }
    }

    return maxVolume;
}
