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
    friend ostream& operator<<(ostream&, const Course&);
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
    Course(const string& = "CS 101", const string& = "Intro to Computers", const string& = "MWF", const double = 3.0, const Date& = Date(), const Date& = Date(), const Time& = Time(), const Time& = Time());
    ~Course();
    
    string getNumber() const;
    string getName() const;
    string getDays() const;
    double getUnits() const;
    
    Date getStartDateInst() const;
    Date getEndDateInst() const;
    Time getStartTimeInst() const;
    Time getEndTimeInst() const;
    
    // strings const reference?
    Course& setNumber(const string&);
    Course& setName(const string&);
    Course& setDays(const string&);
    Course& setUnits(double);
    
    Course& setStartDate(int, int, int);            // void? or cascade
    Course& setStartDate(const Date&);
    Course& setEndDate(int, int, int);              // void?
    Course& setEndDate(const Date&);
    Course& setStartTime(int, int);                 // void?
    Course& setStartTime(const Time&);
    Course& setEndTime(int, int);                   // void?
    Course& setEndTime(const Time&);
    
    double calcDailyDuration() const;
    
    // what to do here?
        // add proper "get date" functions
        // use printDate?
    // Date getStartDate() const;
    // Date getEndDate() const;
    // Time getStartTime() const;
    // Time getEndTime() const;
    
};

#endif
