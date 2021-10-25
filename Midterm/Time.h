// Riley Johnston
// CS137
// Midterm

#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;

class Time
{
    friend ostream& operator<<(ostream&, const Time&);
    friend istream& operator>>(istream&, Time&);
    
    private:
        int hour;  //0-23 (24 hour clock format)
        int minute; //0-59
        int toUniversal(int, char) const;
        int checkHours(int) const;        // validate hrs inputted in standard time (1-12)
    public:
        //default constructor
        Time(int = 0, int = 0);
    
        double operator-(const Time&) const;

        //set functions - not const since they modify private data
        //The & return type enables cascading
        Time& setTime(const Time&);
        Time& setTime(int, int);
        Time& setHour(int);
        Time& setMinute(int);

        //get functions - (normally always declared const)
        int getHour() const;
        int getMinute() const;

        //print functions - (normally always declared const since they do not modify private members, merely inspect
        void printUniversal() const;
        void printStandard()const;
};

#endif
