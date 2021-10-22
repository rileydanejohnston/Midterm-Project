// Riley Johnston
// CS137
// Midterm

#ifndef SEMESTER_H
#define SEMESTER_H

#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Semester {
    friend ostream& operator<<(ostream&, const Semester&);
    // friend istream& operator>>(istream&, Semester&);
    
private:
    string name;
    Date startDate;
    Date endDate;
public:
    Semester(string = "Alex Smith", const Date& = Date(), const Date& = Date());
    
    string getSemesterStr() const;
    string getName() const;
    string getStartDate() const;
    string getEndDate() const;
    
    Semester& setName(string);
    Semester& setStartDate(int, int, int);
    Semester& setEndDate(int, int, int);
};

#endif /* Semester_h */
