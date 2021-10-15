#include "Date.h"
#include <iostream>
using namespace std;

//constructor validates month and calls utility function to validate day
Date::Date(int mn, int dy, int yr)
{
    setDate(mn, dy, yr);
}



void Date::setDate(int mn, int dy, int yr)
{
    if (mn > 0 && mn <= 12)
    {
        month  = mn;
    }

    else
    {
        month = 1;
        cout << "Month set to one - INVALID" << endl;  //BAD DESIGN!
    }
 
    year = yr;  //could also validate year
 
    day = checkDay(dy);  //to validate the day
 
    cout << endl;
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
    
    cout << "Invalid Day " << testDay << " was set to 1" << endl;
    return 1;  //keep data in valid state
}
