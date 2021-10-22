// Riley Johnston
// CS137
// Midterm

#include "Time.h"
#include "Date.h"
#include "Course.h"
#include "Semester.h"
#include "CourseSchedule.h"
#include <iomanip>      // this is definitely needed
// need using namespace std since it's in Time/Date/Course?

int main()
{
    Date startDate(9, 1, 2021);
    Date endDate(12, 15, 2021);
    Time startTime(5, 0);
    Time endTime(1, 5);
    Course biology;
    Semester fall("Fall 2021", startDate, endDate);
    // Course sociology;
    
    CourseSchedule riley("Riley", fall, 4);
    
    cout << riley.getStudent() << endl;
    cout << riley.getSemesterInfo() << endl;
    cout << riley.getNumCourses() << endl;
    
    riley.setStudent("John");
    
    cout << riley.getStudent() << endl;
    
    
    // biology.setNumber("Bio 101").setName("Biology").setDays("TTH").setUnits(4.0);
    // biology.setStartDate(1, 2, 1995).setEndDate(4, 15, 1995).setStartTime(19,0).setEndTime(1,0);
    
    /*
    cout << "Number: " << biology.getNumber() << endl;
    cout << "Name: " << biology.getName() << endl;
    cout << "Days: " << biology.getDays() << endl;
    cout << fixed << setprecision(1) << "Units: " << biology.getUnits() << endl;
    */
     
    //cout << biology << endl;
    /*
    cout << endl;
    
    cout << "Number: " << sociology.getNumber() << endl;
    cout << "Name: " << sociology.getName() << endl;
    cout << "Days: " << sociology.getDays() << endl;
    cout << fixed << setprecision(1) << "Units: " << sociology.getUnits() << endl;
    */
    
    // Time myTime(15, 6);
    // Time newTime1;
    // Time newTime2(6, 35);
    // cout << "Enter a time in this format HH:MM AM (or PM)" << endl;
    // cin >> newTime1;
    
    // newTime1.printStandard();
    // newTime1.printUniversal();
    // newTime2.printUniversal();
    // newTime1.printUniversal();
    // cout << newTime2 - newTime1 << " hours" << endl;
    // cout << newTime1 - newTime2 << " hours" << endl;
    // cout << myTime << endl;
    
    // cout << birthday.getMonth() << endl;
    // cout << birthday.getDay() << endl;
    // cout << birthday.getYear() << endl;
    
    //cout << "Enter a date in this format MM/DD/YYYY -> ";
    //cin >> birthday;
    
    // Date birthday(2,20,2030);
    // Date deathDay(2,20,2030);
    
    /*
    if (birthday <= deathDay)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    */
    
    
    return 0;
}
