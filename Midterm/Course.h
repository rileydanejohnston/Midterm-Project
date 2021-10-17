// Riley Johnston
// CS137
// Midterm

#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Course
{
private:
    string number;
    string name;
    string days;
    double units;
    Date startDate;
    Date endDate;
    Time startTime;
    Time endTime;
public:
    Course(string, string, string, double, const Date&, const Date&, const Time&, const Time&);
    ~Course();
    
    Course& setNumber(string);
    Course& setName(string);
    Course& setDays(string);
    Course& setUnits(double);
    
};

#endif
