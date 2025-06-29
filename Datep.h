/* in file moshabe file date digar hast ama marboot be taghvim shamsi mibashad
* baghi tozihat manand file moshabeh ast
*/




#ifndef DATEP_H
#define DATEP_H
#include <string>
#include <iostream>
using namespace std;

class Datep {
public:
    Datep();
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
