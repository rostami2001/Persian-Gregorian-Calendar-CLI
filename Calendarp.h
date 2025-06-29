/* in file moshbeh file calender digar hast ba in tafavoot ke marboot be taghvim shamsi hast
* yek object az xlass date taghvim shmsi ham darim
*/


#ifndef CALENDARP_H
#define CALENDARP_H

#include <iostream>
#include "Datep.h"

using namespace std;

class Calendarp {
public:
    Calendarp();
    void Run(); //Main Menu system
    void Draw(); //Main calendar draw loop
    void NextDay(); // Print Next Day
    void PreviousDay(); //Print Previous Day 
    void gotoxy(int,int);
    void clrscr();
    void Menu(int);
    void Note();
private:
    Datep currentDate;
};

#endif
#pragma once
