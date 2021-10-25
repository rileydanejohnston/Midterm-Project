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
    string studentName;
    string semesterName;
    Date startDate;
    Date endDate;
    int maxClasses;
    char menuSelect;
    
    cout << "Please enter your name: ";
    getline(cin, studentName);
    
    cout << "Semester start date (mm/dd/yyyy): ";
    cin >> startDate;
    
    cout << "Semester end date (mm/dd/yyyy): ";
    cin >> endDate;
    cin.ignore();
    
    cout << "Semester name (Fall 2021): ";
    getline(cin, semesterName);
    
    cout << "Max number of classes: ";
    cin >> maxClasses;
    
    Semester userSem(semesterName, startDate, endDate);
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
        cout << endl;
        
        
        if (menuSelect == '1')
        {
            cout << "You selected " << menuSelect << endl;
        }
        else if (menuSelect == '2')
        {
            cout << "You selected " << menuSelect << endl;
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
