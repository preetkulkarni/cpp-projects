/*
 * Clock Simulation Program
 * 
 * Description:
 * This program simulates a basic clock system with functionalities to set time, 
 * increment time, and check if two clocks have the same time. 
 * It consists of two classes:
 * - `clockType`: Manages the time and basic operations like incrementing hours, minutes, and seconds.
 * - `extClockType`: Inherits from `clockType` and adds functionality for time zone management.
 * 
 * Written By: Preet Kulkarni
 */

#include<iostream>
#include<string>

class clockType
{
    public: 
        void setTime(int hours, int minutes, int seconds);
        void getTime(int& hours, int& minutes, int& seconds);
        void printTime() const;
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool equalTime(const clockType& otherClock) const;

        clockType();  // Default constructor
        clockType(int hours, int minutes, int seconds);  // Parameterized constructor
    
    private:
        int hr;
        int min;
        int sec;
};

// Set time based on input values, with validation
void clockType::setTime(int hours, int minutes, int seconds)
{
    hr = (0 <= hours && hours < 24) ? hours : 0;
    min = (0 <= minutes && minutes < 60) ? minutes : 0;
    sec = (0 <= seconds && seconds < 60) ? seconds : 0;
}

void clockType::getTime(int& hours, int& minutes, int& seconds)
{
    hours = hr;
    minutes = min;
    seconds = sec;
}

void clockType::printTime() const
{
    std::cout << hr << ":" << min << ":" << sec;
}

// Increment seconds, and handle minute overflow
void clockType::incrementSeconds() 
{
    sec++;
    if (sec > 59) {
        sec = 0;
        incrementMinutes();
    }
}

// Increment minutes, and handle hour overflow
void clockType::incrementMinutes()
{
    min++;
    if (min > 59) {
        min = 0;
        incrementHours();
    }
}

// Increment hours, and reset after 23
void clockType::incrementHours()
{
    hr++;
    if (hr > 23) {
        hr = 0;
    }
}

// Check if two clocks show the same time
bool clockType::equalTime(const clockType& otherClock) const
{
    return (hr == otherClock.hr && min == otherClock.min && sec == otherClock.sec);
}

clockType::clockType() : hr(0), min(0), sec(0) {}

clockType::clockType(int hours, int minutes, int seconds)
{
    setTime(hours, minutes, seconds);
}

// Extended clock class to manage time zones
class extClockType : public clockType
{
    public:
        void setTimeZone(std::string timez);
        std::string getTimeZone() const;

        extClockType(std::string timezone);

    private:
        std::string timezone;
};

void extClockType::setTimeZone(std::string timez)
{
    timezone = timez;
}

std::string extClockType::getTimeZone() const
{
    return timezone;
}

extClockType::extClockType(std::string timez) : clockType(), timezone(timez) {}

int main()
{
    clockType clock1(10, 10, 10);
    std::cout << "Clock 1: ";
    clock1.printTime();
    std::cout << "\n";

    clock1.setTime(20, 20, 20);
    clock1.printTime();
    std::cout << "\n";

    clock1.incrementSeconds();
    clock1.incrementMinutes();
    clock1.incrementHours();
    clock1.printTime();
    std::cout << "\n";

    clockType clock2;
    std::cout << "Clock 2: ";
    clock2.printTime();
    std::cout << "\n";

    std::cout << "Equal? : " << clock2.equalTime(clock1) << "\n";

    clock2.setTime(21, 21, 21);
    clock2.printTime();
    std::cout << "\n";

    std::cout << "Equal? : " << clock2.equalTime(clock1) << "\n";

    return 0;
}
