// Riley Johnston
// CS137
// Midterm

#include <iomanip>
#include "Time.h"


Time::Time(int hour, int minute)
{
    setTime(hour, minute);
}


ostream& operator<<(ostream& output, const Time& right)
{
    output << ((right.hour == 0 || right.hour == 12) ? 12 : right.hour % 12) << ":"
         << setfill ('0') << setw(2) << right.minute << " "
         << setw(2) << (right.hour < 12 ? "AM" : "PM" );
    
    return output;
}


istream& operator>>(istream& input, Time& right)
{
    int hr;
    int min;
    char amPm;
    
    input >> hr;
    input.ignore();                     // ignore colon
    input >> min;
    input >> amPm;
    
    // input validataion: if one input is invalid, reset to default (00:00 am)
    if (hr < 1 || hr > 12)
    {
        hr = 0;
        min = 0;
        amPm = 'a';
    }
    
    if (min < 0 || min > 59)
    {
        min = 0;
        hr = 0;
        amPm = 'a';
    }
    
    if (amPm == 'p' || amPm == 'P')             // both cases will have m (am, pm) do we care about inputting that?
    {
        hr = right.toUniversal(hr);
    }
    else if (amPm != 'p' && amPm != 'P' && amPm != 'a' && amPm != 'A')  // invalid data -> reset to default 00:00 AM
    {
        hr = 0;
        min = 0;
    }
    
    right.setTime(hr, min);
    
    return input;
}


int Time::toUniversal(int hr)
{
    return hr + 12;
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
    minute = (m >= 0 && m < 59) ? m : 0;          //validates minute, if valid set to m, else set to 0
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
          << setw(2) << minute << setw(2) << endl;
}


void Time::printStandard()const  //must be const since prototype is const
{
     cout << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
          << setfill ('0') << setw(2) << minute << " "
          << setw(2) << (hour < 12 ? "AM" : "PM" )<< endl;
}
