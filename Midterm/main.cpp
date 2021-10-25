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
    
    Semester fall;
    
    cout << "Enter the: start date(mm/dd/yyyy), end date (mm/dd/yyyy) and the Semester name (ex fall), " << endl;
    cout << "Please include a space between each value" << endl;
    cin >> fall;
    
    cout << fall << endl;
    
    return 0;
}
