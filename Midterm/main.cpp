// Riley Johnston
// CS137
// Midterm

#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
    // Time myTime(15, 6);
    Time newTime1;
    Time newTime2;
    Time newTime3;
    Time newTime4;
    Time newTime5;
    
    cout << "Enter a time in this format HH:MM AM (or PM)" << endl;
    cin >> newTime1;
    
    //cout << "universal:  " << newTime1.getHour() << ":" << newTime1.getMinute() << endl;
    
    newTime1.printUniversal();
    newTime1.printStandard();
    
    //cout << myTime << endl;
    return 0;
}
