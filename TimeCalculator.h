#ifndef TIMECALCULATOR_H
#define TIMECALCULATOR_H

class TimeCalculator {
public:
    TimeCalculator(double totalDistance, double speed);  // Constructor
    void displayTime() const;  // Display the calculated time

private:
    int hours;
    int minutes;
    int seconds;
    void calculateTime(double totalDistance, double speed);  // Calculate time based on distance and speed
};

#endif
