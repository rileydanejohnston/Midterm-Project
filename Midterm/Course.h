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
    // strings const reference?
    Course(string = "CS 101", string = "Intro to Computers", string = "MWF", double = 3.0, const Date& = Date(), const Date& = Date(), const Time& = Time(), const Time& = Time());
    ~Course();
    
    // strings const reference?
    Course& setNumber(string);
    Course& setName(string);
    Course& setDays(string);
    Course& setUnits(double);
    
};

#endif
