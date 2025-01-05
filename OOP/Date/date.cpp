#include <iostream>
#include <Date.h>

using namespace std;

Date Date::defaultDate(20, 02, 2003);

Date::Date(int day, int month, int year)
{

    if (day == 0)
        this->day = defaultDate.day;
    else
        setDay(day);
    if (month == 0)
        this->month = defaultDate.month;
    else
        setMonth(month);
    if (year == 0)
        this->year = defaultDate.year;
    else
        setYear(year);
}

void Date::setMonth(int month)
{
    if (month >= 1 && month <= 12)
    {
        this->month = month;
    }
}

void Date::setDay(int day)
{
    if (this->month % 2 == 0 && day >= 1 && day <= 30 && !checkleapyear(this->year) && month != 2)
    {
        this->day = day;
    }
    else if (this->month % 2 != 0 && day >= 1 && day <= 31 && !checkleapyear(this->year) && month != 2)
    {
        this->day = day;
    }
    else if (this->month == 2 && day >= 1 && day <= 29 && checkleapyear(this->year))
    {
        this->day = day;
    }
    else if (this->month == 2 && day >= 1 && day <= 28 && !checkleapyear(this->year))
    {
        this->day = day;
    }
}

bool checkleapyear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            return year % 400 == 0;
        }
        return true;
    }
    return false;
}

void Date::addYear(int year)
{
    if (year > 0)
        year += year;
    if (day == 29 && month == 2 && !checkleapyear(year))
    {
        day = 1;
        month = 3;
    }
}

void Date::setDefaultDate(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

int Date::getMonth() const
{
    return month;
}
