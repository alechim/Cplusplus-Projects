class clockType
{
    public:
        void setTime(int, int, int);
        void getTime(int&, int&, int&) const;
        void printTime() const;
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool equalTime(const clockType&) const;

        // Added 3 new functions
        int elapsedTime();
        int remainingTime();
        void differenceTime(const clockType&);

        // Added Setters and Getters
        void setSeconds(int);
        void setMinutes(int);
        void setHours(int);

        int getSeconds() { return sec; }
        int getMinutes() { return min; }
        int getHours() { return hr; }

        clockType(int = 0, int = 0, int = 0);
    private:
        int hr;
        int min;
        int sec;
};