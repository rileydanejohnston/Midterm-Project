#include "Date.h"

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
    setDate(mn, dy, yr);
}

istream& operator>>(istream& input, Date& right)
{
    int mn = 0;
    int dy = 0;
    int yr = 0;
    
    input >> mn;
    input.ignore();
    input >> dy;
    input.ignore();
    input >> yr;
    
    mn = right.checkMonth(mn);
    dy = right.checkDay(dy);
    
    right.setDate(mn, dy, yr);
    
    return input;
}

ostream& operator<<(ostream& output, const Date& right)
{
    output << right.getMonth() << '/' << right.getDay() << '/' << right.getYear();
    return output;
}

int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}
Date& Date::setMonth(int mn)
{
    month = checkMonth(mn);
    return *this;
}
int Date::checkMonth(int mn) const
{
    if (mn > 0 && mn <= 12)
    {
        mn = mn;
    }
    else
    {
        mn = 1;
    }
    
    return mn;
}
Date& Date::setDay(int dy)
{
    day = checkDay(dy);
    return *this;
}
Date& Date::setYear(int yr)         // should we validate year?
{
    year = yr;
    return *this;
}

void Date::setDate(int mn, int dy, int yr)
{
    month = checkMonth(mn);
 
    year = yr;  //could also validate year              // how?
 
    day = checkDay(dy);  //to validate the day
}


//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (testDay > 0 && testDay <= daysPerMonth[month])
    {
     return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if (month == 2 && testDay == 29 && (year  % 400 == 0 || (year % 4  == 0 && year % 100 != 0)))
    {
      return testDay;
    }
    
    return 1;  //keep data in valid state
}
