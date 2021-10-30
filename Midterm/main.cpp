// Last Minute Coders -- Riley Johnston, Christian Napuli, Mateo Zettor, David Akopyan
// CS137
// Midterm Project

#include "Date.h"
#include "Time.h"
#include "Course.h"
#include "Semester.h"
#include "CourseSchedule.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string studentName;
    string semesterName;
    Date semStartDt;
    Date semEndDt;
    int maxClasses = 0;
    char menuSelect = 0;
    
    string courseNum;
    string courseName;
    string courseDays;
    double courseUnits = 0.0;
    
    Time classStartTime;
    Time classEndTime;
    Date classStartDt;
    Date classEndDt;
    
    int deleteCourse = 0;
    
    cout << "Please enter your name: ";
    getline(cin, studentName);
    
    cout << "Semester start date (mm/dd/yyyy): ";
    cin >> semStartDt;
    
    cout << "Semester end date (mm/dd/yyyy): ";
    cin >> semEndDt;
    cin.ignore();
    
    cout << "Semester name (ex. 'Fall 2021'): ";
    getline(cin, semesterName);
    
    cout << "Max number of classes: ";
    cin >> maxClasses;
    
    Semester userSem(semesterName, semStartDt, semEndDt);
    CourseSchedule userSchedule(studentName, userSem, maxClasses);
     
    do
    {
        cout << endl;
        cout << "COURSE ENTRY MENU FOR: " << userSem << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "1) Enter a new course" << endl;
        cout << "2) Remove a course" << endl;
        cout << "3) Print a Semester Schedule" << endl;
        cout << "q) Quit the program" << endl;
        cout << "Your selection: ";
        cin >> menuSelect;
        cin.ignore();
        cout << endl;
        
        
        if (menuSelect == '1')
        {
            // check # of courses - saves time
            if (userSchedule.getNumCourses() == userSchedule.getMaxCourses())
            {
                cout << "You are already taking the maximum number of classes." << endl;
            }
            else
            {
                cout << "Please enter the course number (ex. 'Bio 101'): ";
                getline(cin, courseNum);
                
                cout << "Course name (ex. 'Biology'): ";
                getline(cin, courseName);
                
                cout << "Meeting days (ex. 'MWF'): ";
                getline(cin, courseDays);
                
                cout << "Course units (ex. '4.0'): ";
                cin >> courseUnits;
                
                cout << "Please enter the course start time (ex. '12:00 PM'): ";
                cin >> classStartTime;
                 
                cout << "Course end time (ex. '1:30 PM'): ";
                cin >> classEndTime;
                
                cout << "Please enter the course start date (ex. '1/1/2020'): ";
                cin >> classStartDt;
                
                cout << "Course end date (ex. '4/1/2020'): ";
                cin >> classEndDt;
                
                Course userCourse(courseNum, courseName, courseDays, courseUnits, classStartDt, classEndDt, classStartTime, classEndTime);
                
                if (userSchedule.addCourse(userCourse) == false)
                {
                    cout << endl;
                    cout << "The course date(s) are not within the semester. The course was not added." << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Success! The class was added." << endl;
                }
            }
        }
        else if (menuSelect == '2')
        {
            if (userSchedule.getNumCourses() == 0)
            {
                cout << "Error! You aren't enrolled in any classes." << endl;
            }
            else
            {
                userSchedule.dropCourseDisplay();
                cin >> deleteCourse;
                
                if (userSchedule.removeCourse(deleteCourse) == true)
                {
                    cout << "Success! The course was deleted." << endl;
                }
                else
                {
                    cout << "Invalid selection. The course was not deleted." << endl;
                }
            }
        }
        else if (menuSelect == '3')
        {
            cout << userSchedule;
        }
        else if (menuSelect == 'q' || menuSelect == 'Q')
        {
            cout << "You chose to quit. Thank you for using the program!" << endl;
        }
        else
        {
            cout << "Invalid selection. Please try again." << endl;
        }
        
    }
    while (menuSelect != 'q' && menuSelect != 'Q');
    
    return 0;
}
