class lineType
{
    public:
        double determineSlope();
        bool determineEqualLines(lineType&);
        bool determineParallelLines(lineType&);
        bool determinePerpendicularLines(lineType&);
        void pointOfIntersection(lineType&);

        // Inline Getters
        double getA() const { return a; }
        double getB() const { return b; }

        lineType(double = 0, double = 0, double = 0);
    private:
        double a;
        double b;
        double c;
};