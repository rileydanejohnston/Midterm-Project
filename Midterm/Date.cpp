// Last Minute Coders -- Riley Johnston, Christian Napuli, Mateo Zettor, David Akopyan
// CS137
// Midterm Project

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
    yr = right.checkYear(yr);
    
    right.setDate(mn, dy, yr);
    
    return input;
}

ostream& operator<<(ostream& output, const Date& right)
{
    output << right.getMonth() << '/' << right.getDay() << '/' << right.getYear();
    return output;
}

bool Date::operator<=(const Date& right) const
{
    // check if left is greater than right or equal to
    if (*this < right || *this == right)
    {
        return true;
    }
    return false;
}

bool Date::operator>=(const Date& right) const
{
    // check if left is greater than right or equal to
    if (*this > right || *this == right)
    {
        return true;
    }
    return false;
}

bool Date::operator!=(const Date& right) const
{
    return !(*this == right);
}

bool Date::operator==(const Date& right) const
{
    if (getYear() == right.getYear() && getMonth() == right.getMonth() && getDay() == right.getDay())
    {
        return true;
    }
    return false;
}

bool Date::operator<(const Date& right) const
{
    if (!(*this > right) && *this != right)
    {
        return true;
    }
    return false;
}

bool Date::operator>(const Date& right) const
{
    // check year
    if (getYear() > right.getYear())
    {
        return true;
    }
    // check month (same year)
    else if (getYear() == right.getYear() && getMonth() > right.getMonth())
    {
        return true;
    }
    // check day (same year, month)
    else if (getYear() == right.getYear() && getMonth() == right.getMonth() && getDay() > right.getDay())
    {
        return true;
    }
    
    return false;
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

Date& Date::setDay(int dy)
{
    day = checkDay(dy);
    return *this;
}

Date& Date::setYear(int yr)
{
    year = checkYear(yr);
    return *this;
}

Date& Date::setDate(int mn, int dy, int yr)
{
    month = checkMonth(mn);
 
    year = checkYear(yr);  //could also validate year              // done
 
    day = checkDay(dy);  //to validate the day
    
    return *this;
}

int Date::checkMonth(int mn) const
{
    if (mn > 0 && mn <= 12)
    {
        return mn;
    }
    
    return 1;
}

//PRIVATE COST UTILITY FUNCTION
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    
    if (testDay > 0 && testDay <= daysPerMonth[getMonth()])
    {
     return testDay;
    }
    
    //determine whether testDay is valid for a specific month
    if (getMonth() == 2 && testDay == 29 && (getYear()  % 400 == 0 || (getYear() % 4  == 0 && getYear() % 100 != 0)))
    {
      return testDay;
    }
    
    return 1;  //keep data in valid state
}

int Date::checkYear(int dy) const
{
    if (dy >= 1990 && dy <= 2050)       // validate year is 1990 to 2050
    {
        return dy;
    }
    
    return 1990;                    // default is 1990
}
