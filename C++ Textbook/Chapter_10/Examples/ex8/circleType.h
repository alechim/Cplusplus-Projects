class circleType
{
    public:
        /**
         * Function to set the radius. 
         * Postcondition: if(r >= 0) radius = r; otherwise radius = 0;
         */
        void setRadius(double r);

        /**
         * Function to return the radius. 
         * Postcondition: The value of radius is returned.
         */
        double getRadius();

        /**
         * Function to return the area of a circle. 
         * Postcondition: Area is calculated and returned.
         */
        double area();

        /**
         * Function to return the circumference of a circle. 
         * Postcondition: Circumfeerence is calculated and returned. 
         */
        double circumference();

        /**
         * Constructor with a default parameter. 
         * Radius is set according to the parameter. The default value of the radius is 0.0;
         * Postcondition: radius = r;
         */
        circleType(double r = 0.0);
    private: 
        double radius;
};