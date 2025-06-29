/* in file marboot be daryaft tarikh mibashad ke function afzayesh va kahesh roz ha ham dar in file ast
* function hay "daynames" marboot be rooz hay hafte "monthnames" mah hay sal va "month days" marboot be tedad roz hay har mah hast
*/



#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
using namespace std; 

class Date {
public:
    Date();
    int getYear(); //get the current year
    int getMonth(); //get the current month 
    int getDay(); //get the current day 

    void setDate(int, int, int);

    void IncreaseDay();
    void DecreaseDay();
    static const string DayNames[7]; //all object have weekdays
    static const string MonthNames[12]; //*************** Months
    static const int MonthDays[12]; //*************** Days
private:
    int year;
    int month;
    int day;
    int dayCount;
};

#endif
#pragma once
