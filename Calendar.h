/* in file marboot be taghvim miladi hast ke function ha tarif shode ast
* az class date ham yek object sakhte shode 
*/



#ifndef CALENDAR_H
#define CALENDAR_H

#include <iostream>
#include "Date.h"

using namespace std;

class Calendar {
public:
    Calendar();
    void Run(); //Main Menu system
    void Draw(); //Main calendar draw loop
    void NextDay(); // Print Next Day
    void PreviousDay(); //Print Previous Day 
    void gotoxy(int, int);
    void clrscr();
    void Menu(int);
    void Note();
private:
    Date currentDate;
};

#endif
#pragma once
