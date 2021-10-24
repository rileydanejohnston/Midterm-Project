// Riley Johnston
// CS137
// Midterm

#include "CourseSchedule.h"
#include <iomanip>

CourseSchedule::CourseSchedule(const string &name, const Semester &sem, const int MAX_NUM)
:semester(sem), MAX_SIZE(MAX_NUM)
{
    setStudent(name);
    numCourses = 0;
    coursePtr = new Course[MAX_SIZE];
}

CourseSchedule::~CourseSchedule()
{
    delete [] coursePtr;
}

ostream& operator<<(ostream &output, const CourseSchedule &right)
{
    output << fixed << setprecision(2) << "CLASS SCHEDULE" << endl;
    output << "----------------------------" << endl;
    output << "Name: "          << right.getStudent() << endl;
    output << "Semester: "      << right.getSemesterInst() << endl;
    output << "Total Classes: " << right.getNumCourses() << endl;
    output << "----------------------------" << endl;
    
    for (int i = 0; i < right.getNumCourses(); ++i)
    {
        output << right.coursePtr[i];
        output << endl;
    }
    
    return output;
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

Semester CourseSchedule::getSemesterInst() const
{
    return semester;
}

int CourseSchedule::getNumCourses() const
{
    return numCourses;
}

CourseSchedule& CourseSchedule::setStudent(const string &name)
{
    student = name;
    return *this;
}

CourseSchedule& CourseSchedule::addCourse(const Course& newClass)
{
    // test if class dates are within semester
    bool testClass = checkDates(getSemesterInst(), newClass.getStartDateInst(), newClass.getEndDateInst());
    
    if (testClass == true && getNumCourses() <= MAX_SIZE)
    {
        coursePtr[getNumCourses()] = newClass;      // memberwise assignment
        ++numCourses;
    }
    
    return *this;
}
