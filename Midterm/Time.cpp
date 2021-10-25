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
    int resultHr = 0;
    int resultMin = 0;
    
    int startHr = 0;
    int endHr = 0;
    int startMin = 0;
    int endMin = 0;
    
    // left is larger
    if (getHour() > right.getHour() || (getHour() == right.getHour() && getMinute() > right.getMinute()))
    {
        endHr = getHour();
        endMin = getMinute();
        startHr = right.getHour();
        startMin = right.getMinute();
    }
    else
    {
        endHr = right.getHour();
        endMin = right.getMinute();
        startHr = getHour();
        startMin = getMinute();
    }
    
    
    if (startMin > endMin)
    {
        endHr = endHr - 1;
        endMin = endMin + 60;
    }
    
    resultHr = endHr - startHr;
    resultMin = endMin - startMin;
    
    return resultHr + (resultMin / 60.0);
}


ostream& operator<<(ostream& output, const Time& right)
{
    output << ((right.getHour() == 0 || right.getHour() == 12) ? 12 : right.getHour() % 12) << ":"
         << setfill ('0') << setw(2) << right.getMinute() << " "
         << setw(2) << (right.getHour() < 12 ? "AM" : "PM" );
    
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

Time& Time::setTime(const Time &newTime)
{
    setHour(newTime.getHour());
    setMinute(newTime.getMinute());
    return *this;
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
    minute = (m >= 0 && m <= 59) ? m : 0;          //validates minute, if valid set to m, else set to 0
    return *this;
}

int Time::getHour() const
{
    return hour;
}

int Time::getMinute() const
{
    return minute;
}

void Time::printUniversal()const
{
     cout << setfill('0') << setw(2) << getHour() << ":"
          << setw(2) << getMinute() << setw(2) << endl;
}

void Time::printStandard()const
{
     cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":"
          << setfill ('0') << setw(2) << getMinute() << " "
          << setw(2) << (getHour() < 12 ? "AM" : "PM" )<< endl;
}
