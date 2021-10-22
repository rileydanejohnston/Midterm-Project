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
    
    // is start date within the semester dates?
    bool startDateTest = startDt >= sem.getStartDateInst() && startDt <= sem.getEndDateInst();
    // is end date within the semester dates?
    bool endDateTest = endDt >= sem.getStartDateInst() && endDt <= sem.getEndDateInst();
    
    // if dates are within the semester's date return true
    if (startDateTest == true && endDateTest == true)
    {
        return true;
    }
    return false;
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
