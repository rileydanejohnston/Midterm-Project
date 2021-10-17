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
    cout << "\nThe course has been deleted." << endl;
}

string Course::getNumber() const
{
    return number;
}

string Course::getName() const
{
    return name;
}

string Course::getDays() const
{
    return days;
}

double Course::getUnits() const
{
    return units;
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

void Course::setStartDate(int mn, int dy, int yr)
{
    startDate.setDate(mn, dy, yr);
}

void Course::setEndDate(int mn, int dy, int yr)
{
    endDate.setDate(mn, dy, yr);
}

void Course::setStartTime(int hr, int min)
{
    startTime.setTime(hr, min);
}

void Course::setEndTime(int hr, int min)
{
    endTime.setTime(hr, min);
}
