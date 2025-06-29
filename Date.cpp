/* in file cpp date hast ke marboot be taghvim miladi hast
* dar constractor ma tarikh emrooz ra az system migirim 
* function set date baray set kardan rooz mah va sal hat
* function hae get ham baray azay private tarif shode
* dar function day names asami rooz hay hafte dar araye betartib neveshte shode
* be hamin tartib dar function badi asami mah hay miladi be tartib neveshte shode
* dar function badi tedad rooz hay har mah hast
* va dar function increas va dicrease farayand afzayesh rooz ha va kahesh etefagh miofte
* agar tedad rooz ha az mizan tabi har rooz dar mah bishtar beshe be mah ezafe mishe
* be hamin tartib agar mah az tedad tabiei bishtar beshe be sal ezafe mishe
*/


#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <ctime> //Time dependency 
#include <string>
#include <sstream>


Date::Date() {

    time_t t = time(0); //time(0); or time(NULL); returns the system
    //time in seconds 
    struct tm* now = localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    dayCount = Date::MonthDays[month - 1];

}

void Date::setDate(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

const string Date::DayNames[7] =
{
    "Sun",
    "Mon",
    "Tue",
    "Wen",
    "Thu",
    "Fri",
    "Sat"
};

const string Date::MonthNames[12] = 
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

const int Date::MonthDays[12] = 
{
    31, 28, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31,
};


void Date::IncreaseDay() {
    if (day < MonthDays[month-1])
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

void Date::DecreaseDay() {
    if (day > 1)
        --day;
    else {
        day = MonthDays[month - 2];
        if (month > 1)
            --month;
        else {
            month = 12;
            --year;
        }
    }
}