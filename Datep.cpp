/* in file ham moshabeh file date digar hast ama ba in tafavot ke marboot ba taghvim shamsi mibashad
* dar constructor alave bar daryaft tarikh az system amaliyat tabdil be shamsi ham anjam mishavad
* baghiy function ha moshabe file date digar has ba in tafavot ke rooz ha va mah ha va tedad rooz hay mah
* motefavet va marboot be taghvim shamsi mibashad
*/


#define _CRT_SECURE_NO_WARNINGS
#include "Datep.h"
#include <ctime> //Time dependency 
#include <string>
#include <sstream>


Datep::Datep() {

    time_t t = time(0); 
    struct tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;

    // convert georgian to persion
    long days;
    {
        long gy2 = (month > 2) ? (year + 1) : year;
        long g_d_m[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
        days = 355666 + (365 * year) + ((int)((gy2 + 3) / 4)) - ((int)((gy2 + 99) / 100)) + ((int)((gy2 + 399) / 400)) + day + g_d_m[month - 1];
    }
    long jy = -1595 + (33 * ((int)(days / 12053)));
    days %= 12053;
    jy += 4 * ((int)(days / 1461));
    days %= 1461;
    if (days > 365) {
        jy += (int)((days - 1) / 365);
        days = (days - 1) % 365;
    }
    year = jy;
    if (days < 186) {
        month = 1 + (int)(days / 31);
        day = 1 + (days % 31);
    }
    else {
        month = 7 + (int)((days - 186) / 30);
        day = 1 + ((days - 186) % 30);
    }

    dayCount = Datep::MonthDays[month - 1];

}

void Datep::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

int Datep::getDay() {
    return day;
}

int Datep::getMonth() {
    return month;
}

int Datep::getYear() {
    return year;
}

const string Datep::DayNames[7] =
{
    "1Sh",
    "2sh",
    "3sh",
    "4sh",
    "5sh",
    "Jom",
    "Sha"
};

const string Datep::MonthNames[12] =
{
    "Farvardin",
    "Ordibehesht",
    "Khordad",
    "Tir",
    "Mordad",
    "Shahrivar",
    "Mehr",
    "Aban",
    "Azar",
    "Day",
    "Bahman",
    "Esfand"
};

const int Datep::MonthDays[12] =
{
    31, 31, 31, 31, 31, 31,
    30, 30, 30, 30, 30, 29,
};


void Datep::IncreaseDay() {
    if (day < MonthDays[month - 1])
        ++day;
    else {
        day = 1;
        if (month < 12)
            ++month;
        else {
            month = 1;
            ++year;
        }
    }
}

void Datep::DecreaseDay() {
    if (day > 1)
        --day;
    else {
        day = dayCount;
        if (month > 1)
            --month;
        else {
            month = 12;
            --year;
        }
    }
}