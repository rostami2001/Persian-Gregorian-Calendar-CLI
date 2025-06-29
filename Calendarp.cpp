/* in file niz manand file calender digar hast ba in tafavoot ke marboot ba taghvin shamsi mibashad
* dar function hay moshabeh ba esm hay moshabeh taghvim miladi farayand hay moshabeh anjam mishavad
* va tiziihat moshabeh file calender.cpp taghvim miladi hast
*/


//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include "Calendarp.h"
#include"Calendar.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Datep.h"
#include <conio.h>
#include <windows.h>

Calendarp::Calendarp() {}

void Calendarp::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}

void Calendarp::clrscr()
{
	system("cls");
}

void Calendarp::Run()
{
	bool run = true;

	while (run) {
		char c;
		if (_kbhit())
		{
			c = _getch();
			switch (c)
			{
			case 'n':
				clrscr();
				gotoxy(10, 17);
				cout << "Press 'n' to next, 'p' to previous and 'q' to quit";
				gotoxy(10, 18);
				cout << "Press 's' to add note, Press 'b' to go to the main menu";
				NextDay();
				Draw();
				break;
			case 'p':
				clrscr();
				gotoxy(10, 17);
				cout << "Press 'n' to next, 'p' to previous and 'q' to quit";
				gotoxy(10, 18);
				cout << "Press 's' to add note, Press 'b' to go to the main menu";
				PreviousDay();
				Draw();
				break;
			case'b':
			{
				clrscr();
				gotoxy(10, 10);
				cout << "Press the number of each calendar to select";
				gotoxy(12, 11);
				cout << "1-Gorgian     2-Persian";
				int adad;
				adad = _getch();
					clrscr();
					gotoxy(10, 17);
					cout << "Press 'n' to next, 'p' to previous and 'q' to quit";
					gotoxy(10, 18);
					cout << "Press 's' to add note, Press 'b' to go to the main menu";
					Menu(adad);
					run = false;
			}
				break;
			case's':
			{
				clrscr();
				Note();
				break;
			}
			case 'q':
				run = false;
				break;
			default:
				cout << endl << "Invalid input." << endl;
				break;
			}
		}
	}
}

void Calendarp::Draw()
{
	gotoxy(10, 17);
	cout << "Press 'n' to next, 'p' to previous and 'q' to quit";
	gotoxy(10, 18);
	cout << "Press 's' to add note, Press 'b' to go to the main menu";

	int year = currentDate.getYear();
	int month = currentDate.getMonth();
	int day = currentDate.getDay();

	gotoxy(20, 5);
	cout << "---------------------------";
	gotoxy(20, 6);
	cout << "    " << year << "   " << Datep::MonthNames[month - 1] << "   " << day << endl;
	gotoxy(20, 7);
	cout << "---------------------------";

	gotoxy(20, 8);
	for (int i = 0; i < sizeof Datep::DayNames / sizeof Datep::DayNames[0]; ++i) {
		cout << Datep::DayNames[i] << " ";
	}

	int y = year - (month < 3);
	static int t[] = { 4 ,0 ,2 ,5 ,1 ,4 ,0 ,2 ,4 ,6 ,1 ,3 };
	int startingDay;
	int d = 1;
	if ((month == 1)||(month==2)) {
		d = 0;
	}
	startingDay = ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + d) % 7);
	int dayCount = Datep::MonthDays[month - 1];


	gotoxy(20, 9);
	for (int x = 0; x < startingDay; ++x) {
		cout << "    ";
	}

	int n = 10;
	for (int d = 0; d < dayCount; ++d) {
		if (d < 9)
			cout << "0" << d + 1 << "  ";
		else
			cout << d + 1 << "  ";
		++startingDay;
		if (startingDay == 7) {
			startingDay = 0;
			gotoxy(20, n);
			n++;
		}
	}
}

void Calendarp::NextDay() {
	currentDate.IncreaseDay();
}

void Calendarp::PreviousDay() {
	currentDate.DecreaseDay();
}

void Calendarp::Menu(int adad) {
	if (adad == '1') {
		Calendar c1;
		c1.Draw();
		c1.Run();
	}
	if (adad == '2') {
		Draw();
		Run();
	}
}

void Calendarp::Note() {
	cout << "add note:(press * then enter when finished!" << endl;
	ifstream no;
	ofstream note;
	string line;

	no.open("note.txt");
	while (no) {

		getline(no, line);
		cout << line << endl;
	}
	no.close();

	note.open("note.txt");
	while (note) {
		getline(cin, line);

		
		if (line == "*")
			break;

		note << line << endl;
	}
	note.close();
}