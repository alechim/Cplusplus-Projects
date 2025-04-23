#include <iostream>

using namespace std;

// Class
class rectangleArea
{
    private:
        double length;
        double width;
        double area;
    public:
        void setData();
        double calculateArea();
        void getArea() const;
};

int main()
{
    rectangleArea rectangle;

    rectangle.setData();
    rectangle.calculateArea();
    rectangle.getArea();

    return 0;
}

// Class Function Definitions
/**
 * rectangleArea::setData: Prompts user for length and width
 */
void rectangleArea::setData()
{
    cout << "Enter Length of the Rectangle: ";
    cin >> length;

    cout << "Enter Width of the Rectangle: ";
    cin >> width;
}

/**
 * rectangleArea::calculateArea: Calculate the area of a rectangle
 */
double rectangleArea::calculateArea()
{
    area = length * width;
    return area;
}

/**
 * rectangleArea::getArea() const: Displays all prior information
 */
void rectangleArea::getArea() const
{
    cout << "Entered Length: " << length << endl;
    cout << "Entered Width: " << width << endl;
    cout << "Calculated Area: " << area << endl;
}