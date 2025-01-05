#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
    static Date defaultDate;

public:
    Date(int day = 0, int month = 0, int year = 0);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);
    void addDay(int day);
    void addMonth(int month);
    void addYear(int year);
    void setDefaultDate(int day, int month, int year);
};