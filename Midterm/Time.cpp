// Riley Johnston
// CS137
// Midterm

#include <iomanip>
#include "Time.h"


Time::Time(int hour, int minute)
{
    setTime(hour, minute);
}

double Time::operator-(const Time& right) const
{
    double timeDifference = 0.0;
    
    int resultHr = 0;
    int resultMin = 0;
    
    int startHr = 0;
    int endHr = 0;
    int startMin = 0;
    int endMin = 0;
    
    
    if (getHour() > right.getHour())            // left is larger by hour
    {
        endHr = getHour();
        endMin = getMinute();
        startHr = right.getHour();
        startMin = right.getMinute();
        cout << "left is larger" << endl;
    }
    else if (getHour() < right.getHour())       // right larger by hour
    {
        endHr = right.getHour();
        endMin = right.getMinute();
        startHr = getHour();
        startMin = getMinute();
        cout << "right is larger" << endl;
    }
    else if (getHour() == right.getHour() && getMinute() > right.getMinute())       // left larger by minutes
    {
        startHr = right.getHour();
        startMin = right.getMinute();
        endHr = getHour();
        endMin = getMinute();
        cout << "hours equal, left min larger" << endl;
    }
    else if (getHour() == right.getHour() && getMinute() < right.getMinute())       // right larger by minutes
    {
        endHr = right.getHour();
        endMin = right.getMinute();
        startHr = getHour();
        startMin = getMinute();
        cout << "hours equal, right min larger" << endl;
    }
    
    
    if (startMin > endMin)                  // left hours/mins > right hours/mins
    {
        endHr = endHr - 1;
        endMin = endMin + 60;
    }
    
    
    resultHr = endHr - startHr;
    resultMin = endMin - startMin;
    
    
    timeDifference = resultHr + (resultMin / 60.0);
    
    return timeDifference;
}


ostream& operator<<(ostream& output, const Time& right)
{
    output << ((right.hour == 0 || right.hour == 12) ? 12 : right.hour % 12) << ":"
         << setfill ('0') << setw(2) << right.minute << " "
         << setw(2) << (right.hour < 12 ? "AM" : "PM" );
    
    return output;
}

int Time::checkHours(int hr) const
{
    if (hr > 12 || hr < 1)
    {
        return 0;
    }
    return hr;
}


istream& operator>>(istream& input, Time& right)
{
    int hr = 0;
    int min = 0;
    char amPm = 0;
    
    input >> hr;
    input.ignore();                     // ignore colon
    input >> min;
    input >> amPm;
    
    hr = right.checkHours(hr);        // validate hrs is standard (1-12)

    // assume they meant am?
    if (amPm != 'p' && amPm != 'P' && amPm != 'a' && amPm != 'A')
    {
        amPm = 'a';
    }
    
    // convert to universal
    hr = right.toUniversal(hr, amPm);
    
    
    right.setTime(hr, min);     // validates hours & minutes
    
    return input;
}


int Time::toUniversal(int hr, char amPm) const
{
    // 12 pm
    if ((amPm == 'p' || amPm == 'P') && hr == 12)
    {
        return 12;
    }
    // 12 am
    else if ((amPm == 'a' || amPm == 'A') && hr == 12)
    {
        return 0;
    }
    // am - just return hr
    else if (amPm == 'a' || amPm == 'A')
    {
        return hr;
    }
    
    // pm - add 12 for universal time
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
