// Riley Johnston
// CS137
// Midterm

#include "Course.h"
#include <iomanip>

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

ostream& operator<<(ostream& output, const Course &right)
{
    output << fixed << setprecision(2) << "Course Info: " << setw(10) << right.getNumber() << " -- " << right.getName() << endl;
    output << "# of Units: "    << setw(8) << right.getUnits() << endl;
    output << "Course Dates: "  << setw(10) << right.getStartDateInst() << " -- " << right.getEndDateInst() << endl;
    output << "Meeting Days: "  << setw(5) << right.getDays() << endl;
    output << "Meeting Times: " << setw(8) << right.getStartTimeInst() << " -- " << right.getEndTimeInst() << endl;
    output << "Daily Duration: " << right.calcDailyDuration() << " hours" << endl;
    
    return output;
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

Date Course::getStartDateInst() const
{
    return startDate;
}

Date Course::getEndDateInst() const
{
    return endDate;
}

Time Course::getStartTimeInst() const
{
    return startTime;
}

Time Course::getEndTimeInst() const
{
    return endTime;
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
    // validate units? can't be 0 or negative. upper limit? i'll say 10 for now
    units = (numUnits > 0 && numUnits <= 10) ? numUnits : 3.0;
    return *this;
}

Course& Course::setStartDate(int mn, int dy, int yr)
{
    startDate.setDate(mn, dy, yr);
    return *this;
}

Course& Course::setEndDate(int mn, int dy, int yr)
{
    endDate.setDate(mn, dy, yr);
    return *this;
}

Course& Course::setStartTime(int hr, int min)
{
    startTime.setTime(hr, min);
    return *this;
}

Course& Course::setEndTime(int hr, int min)
{
    endTime.setTime(hr, min);
    return *this;
}

double Course::calcDailyDuration() const
{
    return endTime - startTime;
}
