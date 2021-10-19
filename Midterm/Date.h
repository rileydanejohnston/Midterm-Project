// Riley Johnston
// CS137
// Midterm


#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
        friend ostream& operator<<(ostream&, const Date&);
        friend istream& operator>>(istream&, Date&);
    private:
        int month; //1-12
        int day; //1-31 depending on month
        int year; //any year

        //utility function to check if day is proper for month and year
        int checkDay(int) const;
        int checkMonth(int) const;      // not in instructions
        int checkYear(int) const;      // not in instructions
    public:
        Date(int = 1, int = 1, int = 1990);
    
        bool operator<=(const Date&) const;
        bool operator>=(const Date&) const;
        bool operator!=(const Date&) const;
        bool operator==(const Date&) const;
        bool operator<(const Date&) const;
        bool operator>(const Date&) const;
    
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        string getDateStr() const;
    
        Date& setDate(int, int, int);
        Date& setMonth(int);
        Date& setDay(int);
        Date& setYear(int);
        
};

#endif
