// Last Minute Coders -- Riley Johnston, Christian Napuli, Mateo Zettor, David Akopyan
// CS137
// Midterm Project

#include "Semester.h"

Semester::Semester(const string &nm, const Date &startDt, const Date &endDt)
: startDate(startDt), endDate(endDt)
{
    setSemName(nm);
}

ostream& operator<<(ostream &output, const Semester &right)
{
    output << right.getSemName() << " (" << right.getStartDateInst() << " - " << right.getEndDateInst() << ")";
    return output;
}


istream& operator>>(istream &input, Semester &right)
{
    string semName;
    Date start;
    Date end;
    
    input >> start;
    input >> end;
    input.ignore();             // ignore space in keyboard buffer
    getline(cin, semName);
    
    right.setSemName(semName).setStartDate(start).setEndDate(end);
    
    return input;
}


string Semester::getSemName() const
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

Semester& Semester::setSemName(const string &nm)
{
    name = nm;
    return *this;
}

Semester& Semester::setStartDate(const Date &startDt)
{
    startDate.setDate(startDt.getMonth(), startDt.getDay(), startDt.getYear());
    return *this;
}

Semester& Semester::setStartDate(int mn, int dy, int yr)
{
    startDate.setDate(mn, dy, yr);
    return *this;
}

Semester& Semester::setEndDate(const Date &endDt)
{
    endDate.setDate(endDt.getMonth(), endDt.getDay(), endDt.getYear());
    return *this;
}

Semester& Semester::setEndDate(int mn, int dy, int yr)
{
    endDate.setDate(mn, dy, yr);
    return *this;
}
