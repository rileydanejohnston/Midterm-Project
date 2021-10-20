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
    output << right.getSemester();
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

string Semester::getSemester() const
{
    return getName() + " (" + getStartDate() + " - " + getEndDate() + ")";
}

string Semester::getStartDate() const
{
    return startDate.getDateStr();
}

string Semester::getEndDate() const
{
    return endDate.getDateStr();
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
