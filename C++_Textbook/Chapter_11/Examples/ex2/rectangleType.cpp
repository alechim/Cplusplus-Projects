#include <iostream>
#include "rectangleType.h"

using namespace std;

// Class Function Definitions
void rectangleType::setDimension(double l, double w)
{
    length = l >= 0.0 ? l : 0.0;
    width = w >= 0.0 ? w : 0.0;
}

double rectangleType::getLength() const { return length; }
double rectangleType::getWidth() const { return width; }
double rectangleType::area() const { return length * width; }
double rectangleType::perimeter() const { return 2 * (length + width); }

void rectangleType::print() const
{
    cout << "Length = " << length << "; Width = " << width;
}

rectangleType::rectangleType()
{
    length = 0.0;
    width = 0.0;
}

rectangleType::rectangleType(double l, double w)
{
    setDimension(l, w);
}