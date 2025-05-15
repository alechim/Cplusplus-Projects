// Example 6-C: Filling a Swimming Pool
#include <iostream>
#include <iomanip>

using namespace std;

// ***Globals***
const double GALLONS_IN_A_CUBIC_FOOT = 7.48;

// ***Function Prototypes***
double poolCapacity(double len, double wid, double dep);
void poolFillTime(double len, double wid, double dep, double fRate, int& fTime);
void print(int fTime);

int main()
{
    // Variables
    double length = 0.0;
    double width = 0.0;
    double depth = 0.0;
    double fillRate = 0.0;
    int fillTime = 0;

    cout << fixed << showpoint << setprecision(2);
    cout << "Enter the length, width, and the depth of the pool, (in feet): ";
    cin >> length >> width >> depth;
    cout << endl;

    cout << "Enter the rate of the water, (in gallons per minute): ";
    cin >> fillRate;
    cout << endl;

    poolFillTime(length, width, depth, fillRate, fillTime);
    print(fillTime);

    return 0;
}

// ***Functions***
double poolCapacity(double len, double wid, double dep)
{
    double volume = 0.0;
    double poolWaterCapacity = 0.0;

    volume = len * wid * dep;
    poolWaterCapacity = volume * GALLONS_IN_A_CUBIC_FOOT;

    return poolWaterCapacity;
}

void poolFillTime(double len, double wid, double dep, double fRate, int& fTime)
{
    double poolWaterCapacity = 0.0;
    poolWaterCapacity = poolCapacity(len, wid, dep);
    fTime = static_cast<int>(poolWaterCapacity / fRate + 0.5);
}

void print(int fTime)
{
    cout << "The time to fill the pool is approximately: " << fTime / 60 << " hour(s) and " << fTime % 60 << " minute(s)." << endl;
}