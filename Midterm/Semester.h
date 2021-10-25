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
    Semester(const string& = "Alex Smith", const Date& = Date(), const Date& = Date());
    
    string getName() const;
    Date getStartDateInst() const;            // returns instance for comparisons
    Date getEndDateInst() const;              // returns instance for comparisons
    
    Semester& setName(const string&);
    Semester& setStartDate(const Date&);
    Semester& setStartDate(int, int, int);
    Semester& setEndDate(int, int, int);
    Semester& setEndDate(const Date&);
};

#endif /* Semester_h */
