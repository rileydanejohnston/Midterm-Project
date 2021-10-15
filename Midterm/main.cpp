// Riley Johnston
// CS137
// Midterm

#include "Time.h"
#include "Date.h"
#include <iostream>
using namespace std;

int main()
{
    // Time myTime(15, 6);
    // Time newTime1;
    // Time newTime2(6, 35);
    // cout << "Enter a time in this format HH:MM AM (or PM)" << endl;
    // cin >> newTime1;
    // cout << "universal:  " << newTime1.getHour() << ":" << newTime1.getMinute() << endl;
    // newTime2.printUniversal();
    // newTime1.printUniversal();
    // cout << newTime2 - newTime1 << " hours" << endl;
    // cout << newTime1 - newTime2 << " hours" << endl;
    // cout << myTime << endl;
    
    Date birthday(2,20,2030);
    Date deathDay(2,20,2030);
    
    // cout << birthday.getMonth() << endl;
    // cout << birthday.getDay() << endl;
    // cout << birthday.getYear() << endl;
    
    //cout << "Enter a date in this format MM/DD/YYYY -> ";
    //cin >> birthday;
    
    
    if (birthday == deathDay)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    
    
    
    
    return 0;
}
