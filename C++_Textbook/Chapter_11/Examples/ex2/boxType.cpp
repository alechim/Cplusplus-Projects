#include <iostream>
#include "boxType.h"

using namespace std;

void boxType::setDimension(double l, double w, double h)
{
    rectangleType::setDimension(l, w);
    height = h >= 0.0 ? h : 0.0;
}

double boxType::getHeight() const { return height; }

double boxType::area() const
{ 
    return 2.0 * (getLength() * getWidth() + getLength() * height + getWidth() * height);
}

double boxType::volume() const { return rectangleType::area() * height; }

void boxType::print() const
{
    rectangleType::print();
    cout << "; Height = " << height;
}

boxType::boxType()
{
    height = 0.0;
}

boxType::boxType(double l, double w, double h) : rectangleType(l, w)
{
    height = h >= 0.0 ? h : 0.0;
}