// Riley Johnston
// CS137
// Midterm

#include <iostream>
#include <iomanip>
using namespace std;

#include "Time.h"


Time::Time(int hour, int minute)
{
 setTime(hour, minute);
}


//setTime function now is set up to enable cascading
Time& Time::setTime(int hour, int minute)
{
 setHour(hour);
 setMinute(minute);
 return *this;
}


//setHour function is now set up to enable cascading
Time& Time::setHour(int h)
{
  hour = (h >= 0 && h < 24) ? h : 0;            //validates hour, if valid set to h, else set to 0
  return *this;
}


//setMinute function is now set up to enable cascading
Time& Time::setMinute(int m)
{
  minute = (m >= 0 && m < 24) ? m : 0;          //validates minute, if valid set to m, else set to 0
  return *this;
}


/*GET FUNCTIONS:  Do not modify private member data normally always const*/

//get Hour
int Time::getHour() const  //must be const since prototype is const
{
    return hour;
}


//get Minute
int Time::getMinute() const  //must be const since prototype is const
{
    return minute;
}


/*PRINT FUNCTIONS:  Normally do not modify private member data so should be const*/

void Time::printUniversal()const  //must be const since prototype is const
{
     cout << setfill('0') << setw(2) << hour << ":"
          << setw(2) << minute << ":" << setw(2) << endl;
}


void Time::printStandard()const  //must be const since prototype is const
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
          << setfill ('0') << setw(2) << minute << ":"
          << setw(2) << (hour < 12 ? "AM" : "PM" )<< endl;
}
