// Riley Johnston
// CS137
// Midterm

#include "Semester.h"

Semester::Semester(string nm, const Date &startDt, const Date &endDt)
: startDate(startDt), endDate(endDt)
{
    setName(nm);
}

ostream& operator<<(ostream &output, const Semester &right)
{
    output << right.getName() << " (" << right.getStartDateInst() << " - " << right.getEndDateInst() << ")";
    return output;
}

/*
istream& operator>>(istream &input, Semester &right)
{
    
    return input;
}
*/

string Semester::getName() const
{
    return name;
}

Date Semester::getStartDateInst() const
{
    return startDate;
}

Date Semester::getEndDateInst() const
{
    return endDate;
}

Semester& Semester::setName(string nm)
{
    name = nm;
    return *this;
}

Semester& Semester::setStartDate(int mn, int dy, int yr)
{
    startDate.setDate(mn, dy, yr);
    return *this;
}

Semester& Semester::setEndDate(int mn, int dy, int yr)
{
    endDate.setDate(mn, dy, yr);
    return *this;
}
