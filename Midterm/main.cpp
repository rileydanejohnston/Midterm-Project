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
    // get user name
    // get semester name
    // get sem start date
    // get sem end date
    string name;
    int maxClasses;
    Semester userSem;
    
    cout << "Please enter your name: ";
    getline(cin, name);
    
    cout << "Enter the: start date(mm/dd/yyyy), end date (mm/dd/yyyy) and the Semester name (ex fall), " << endl;
    cout << "Please include a space between each value" << endl;
    cin >> userSem;
    
    cout << "Please enter the maximum number of classes you can take: ";
    cin >> maxClasses;
    
    CourseSchedule userSchedule(name, userSem, maxClasses);
    
    cout << userSchedule << endl;
    
    
    return 0;
}
