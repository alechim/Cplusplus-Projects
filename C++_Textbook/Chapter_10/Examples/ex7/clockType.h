class clockType
{
    public:
        /**
         * Function to set the time. The time is set according to the parameters
         * Postcondition: hr = hours; min = minutes; sec = seconds;
         * - The function checks whether the values of hours, minutes, and seconds are valid. If a value
         *   is invalid, the default value 0 is assigned.
         */
        void setTime(int hours, int minutes, int seconds);

        /**
         * Function to return the time.
         * Postcondition: hours = hr; minutes = min; seconds = sec;
         */
        void getTime(int& hours, int& minutes, int& seconds) const;

        /**
         * Function to print the time.
         * Postcondition: The time is printed in the form hh:mm:ss.
         */
        void printTime() const;

        /**
         * Function to increment the time by one second.
         * Postcondition: The time is incremented by one second.
         * - If the before-increment time is 23:59:59, the time is reset to 00:00:00.
         */
        void incrementSeconds();

        /**
         * Function to increment the time by one minute.
         * Postcondition: The time is incremented by one minute.
         * - If the before-increment time is 23:59:53, the time is reset to 00:00:53.
         */
        void incrementMinutes();

        /**
         * Function to increment the time by one hour.
         * Postcondition: The time is incremented by one hour.
         * - If the before-increment time is 23:45:53, the time is reset to 00:45:53.
         */
        void incrementHours();

        /**
         * Function to compare the two times.
         * Postcondition: Returns true if this time is equal to otherClock; otherwise, return false.
         */
        bool equalTime(const clockType& otherClock) const;

        /**
         * Constructor with parameters
         * The time is set according to the parameters.
         * Postcondition: hr = hours; min = minutes; sec = seconds;
         * - The constructor checks whether the values of hours, minutes, and seconds are valid. If
         *   a value is invalid, the default value 0 is assigned.
         */
        clockType(int hours, int minutes, int seconds);

        /**
         * Default constructor
         * The time is set to 00:00:00
         * Postcondition: hr = 0; min = 0; sec = 0;
         */
        clockType();
    private:
        int hr;         // Variable to store the hours
        int min;        // Variable to store the minutes
        int sec;        // Variable to store the seconds
};