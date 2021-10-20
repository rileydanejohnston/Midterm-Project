// Riley Johnston
// CS137
// Midterm

#include "Semester.h"

Semester::Semester(string nm, const Date &startDt, const Date &endDt)
: startDate(startDt), endDate(endDt)
{
    setName(nm);
}

string Semester::getName() const
{
    return name;
}

Semester& Semester::setName(string nm)
{
    name = nm;
    return *this;
}
