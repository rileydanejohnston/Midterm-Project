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
}

bool CourseSchedule::checkDates(const Semester &sem, const Date &startDt, const Date &endDt) const
{
    // if start date is before semester date
    // if end date is after semester date
        // return false
    
    if (sem.getStartDateInst() > startDt || sem.getEndDateInst() < endDt)
    {
        return false;
    }
    return true;
}

string CourseSchedule::getStudent() const
{
    return student;
}

string CourseSchedule::getSemesterInfo() const
{
    return semester.getSemesterStr();
}

int CourseSchedule::getNumCourses() const
{
    return numCourses;
}

CourseSchedule& CourseSchedule::setStudent(string name)
{
    student = name;
    return *this;
}

//bool checkDates(const Semester &sem, const Date &startDate, const Date &endDate) const;
