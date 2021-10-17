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
    
    string getNumber() const;
    string getName() const;
    string getDays() const;
    double getUnits() const;
    
    // strings const reference?
    Course& setNumber(string);
    Course& setName(string);
    Course& setDays(string);
    Course& setUnits(double);
    
    void setStartDate(int, int, int);            // void?
    void setEndDate(int, int, int);              // void?
    void setStartTime(int, int);                 // void?
    void setEndTime(int, int);                   // void?
    
    // what to do here?
        // add proper "get date" functions
        // use printDate?
    // Date getStartDate() const;
    // Date getEndDate() const;
    // Time getStartTime() const;
    // Time getEndTime() const;
    
};

#endif
