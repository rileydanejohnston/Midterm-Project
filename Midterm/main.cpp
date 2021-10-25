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
    char menuSelect;
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
