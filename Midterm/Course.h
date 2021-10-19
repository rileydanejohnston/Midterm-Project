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
    Course(string = "CS 101", string = "Intro to Computers", string = "MWF", double = 3.0, const Date& = Date(), const Date& = Date(), const Time& = Time(), const Time& = Time());
    ~Course();
    
    string getNumber() const;
    string getName() const;
    string getDays() const;
    double getUnits() const;
    
    string getStartDate() const;
    string getEndDate() const;
    string getStartTime() const;
    string getEndTime() const;
    
    // strings const reference?
    Course& setNumber(string);
    Course& setName(string);
    Course& setDays(string);
    Course& setUnits(double);
    
    Course& setStartDate(int, int, int);            // void? or cascade
    Course& setEndDate(int, int, int);              // void?
    Course& setStartTime(int, int);                 // void?
    Course& setEndTime(int, int);                   // void?
    
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
