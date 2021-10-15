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

    public:
        Date(int = 1, int = 1, int = 1990);
        ~Date();
        void setDate(int, int, int);
};

#endif
