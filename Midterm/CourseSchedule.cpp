// Last Minute Coders -- Riley Johnston, Christian Napuli, Mateo Zettor, David Akopyan
// CS137
// Midterm Project

#include "CourseSchedule.h"
#include <iomanip>

CourseSchedule::CourseSchedule(const string &name, const Semester &sem, const int MAX_NUM)
:semester(sem), MAX_SIZE(MAX_NUM)
{
    setStudent(name);
    numCourses = 0;
    coursePtr = new Course[getMaxCourses()];
}

CourseSchedule::CourseSchedule(const CourseSchedule &csToCopy)
:semester(csToCopy.getSemesterInst()), MAX_SIZE(csToCopy.getMaxCourses())
{
    setStudent(csToCopy.getStudent());
    numCourses = csToCopy.getNumCourses();
    coursePtr = new Course[getMaxCourses()];
    
    for (int i = 0; i < getMaxCourses(); ++i)
    {
        coursePtr[i] = csToCopy.coursePtr[i];
    }
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

int CourseSchedule::getMaxCourses() const
{
    return MAX_SIZE;
}

CourseSchedule& CourseSchedule::setStudent(const string &name)
{
    student = name;
    return *this;
}

bool CourseSchedule::addCourse(const Course& newClass)
{
    // test if class dates are within semester
    bool testClass = checkDates(getSemesterInst(), newClass.getStartDateInst(), newClass.getEndDateInst());
    
    if (testClass == true && getNumCourses() <= getMaxCourses())
    {
        coursePtr[getNumCourses()] = newClass;      // memberwise assignment
        ++numCourses;
        return true;
    }
    
    return false;
}

bool CourseSchedule::removeCourse(int classNum)
{
    int arrayBound = getNumCourses() - 1;
    
    // validate input
    if (classNum < 1 || classNum > getNumCourses())
    {
        return false;
    }
    
    classNum = classNum - 1;        // represents array position
    
    for (int i = classNum; i < arrayBound; ++i)
    {
        coursePtr[i] = coursePtr[ i + 1 ];
    }
    
    --numCourses;               // decrease number of classes by 1
    return true;
}

void CourseSchedule::dropCourseDisplay() const
{
    cout << "Which class do you want to delete?" << endl;;

    for (int i = 0; i < getNumCourses(); ++i)
    {
        cout << i + 1 << ") " << coursePtr[i].getNumber() << endl;
    }
    
    cout << "Selection (enter an integer): ";
}
