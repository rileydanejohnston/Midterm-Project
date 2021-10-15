#ifndef DATE_H
#define DATE_H

class Date
{
    private:
        int month; //1-12
        int day; //1-31 depending on month
        int year; //any year

        //utility function to check if day is proper for month and year
        int checkDay(int) const;
        int checkMonth(int) const;      // not in instructions
    public:
        Date(int = 1, int = 1, int = 1990);
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        Date& setMonth(int);
        Date& setDay(int);
        Date& setYear(int);
        void setDate(int, int, int);
};

#endif
