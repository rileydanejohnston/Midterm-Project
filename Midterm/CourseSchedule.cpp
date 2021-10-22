// Riley Johnston
// CS137
// Midterm

#include "CourseSchedule.h"

CourseSchedule::CourseSchedule(string name, const Semester &sem, const int MAX_NUM)
:semester(sem), MAX_SIZE(MAX_NUM)
{
    student = name;
    numCourses = 0;
    coursePtr = new Course[MAX_SIZE];
}

CourseSchedule::~CourseSchedule()
{
    delete [] coursePtr;
    cout << "Course array is free" << endl;
}

string CourseSchedule::getStudent() const
{
    return student;
}

//bool checkDates(const Semester &sem, const Date &startDate, const Date &endDate) const;
