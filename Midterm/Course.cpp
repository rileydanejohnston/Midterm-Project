// Riley Johnston
// CS137
// Midterm

#include "Course.h"

Course::Course(string num, string title, string meetDays, double numUnits, const Date &startDt, const Date &endDt, const Time &startTm, const Time &endTm)
:startDate(startDt), endDate(endDt), startTime(startTm), endTime(endTm)
{
    setNumber(num).setName(title).setDays(meetDays).setUnits(numUnits);
}
Course::~Course()
{
    cout << "The course has been deleted." << endl;
}

Course& Course::setNumber(string num)
{
    number = num;
    return *this;
}
Course& Course::setName(string title)
{
    name = title;
    return *this;
}
Course& Course::setDays(string meetDays)
{
    days = meetDays;
    return *this;
}
Course& Course::setUnits(double numUnits)
{
    units = numUnits;
    return *this;
}
