// Riley Johnston
// CS137
// Midterm

#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H

#include "Semester.h"
#include "Course.h"
#include <iostream>
using namespace std;

class CourseSchedule
{
    friend ostream& operator<<(ostream&, const CourseSchedule&);
private:
    string student;
    Semester semester;
    Course *coursePtr;
    const int MAX_SIZE;
    int numCourses;
    
    bool checkDates(const Semester&, const Date&, const Date&) const;
public:
    CourseSchedule(const string& = "Alex Smith", const Semester& = Semester(), const int = 4);
    ~CourseSchedule();
    
    string getStudent() const;
    Semester getSemesterInst() const;
    int getNumCourses() const;
    int getMaxCourses() const;
    
    CourseSchedule& setStudent(const string&);
    CourseSchedule& addCourse(const Course&);        // cascading?
    // CourseSchedule& removeCourse(const Course&);
};

#endif
