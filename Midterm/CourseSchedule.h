// Last Minute Coders -- Riley Johnston, Christian Napuli, Mateo Zettor, David Akopyan
// CS137
// Midterm Project

#ifndef COURSESCHEDULE_H
#define COURSESCHEDULE_H

#include "Semester.h"
#include "Course.h"
#include <string>
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
    CourseSchedule(const CourseSchedule&);
    ~CourseSchedule();
    
    string getStudent() const;
    Semester getSemesterInst() const;
    int getNumCourses() const;
    int getMaxCourses() const;
    
    CourseSchedule& setStudent(const string&);
    bool addCourse(const Course&);
    bool removeCourse(int);
    void dropCourseDisplay() const;
};

#endif
