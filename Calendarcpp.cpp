/* in file marboot be taghvim miladi hast functin hay gotoxy va clrscr betartib baray raftam be makan delkhah dar safhe va pak kardan safhe ast
* dar function run entekhab ha soorat migirad va ba tavajoh be entekhab hay karbar be tavabe mord nazar ferestade mishavad
dar function drow piyade sazi taghvim soorat migirad shekl koli taghvim dar in bakhsh chap mishavad
dar in function barrasi mishad ke shoro ros bayad az koja bashad va be andaze an ha fazay khali jolo miravad
dar 2 function badi ba komak object class date afzayesh va kahesh anjam mishavad
dar function menu ba tavajoh be entekhab karbar taghvim mord nazar farakhani mishavad
dar function akhar file txt khande va neveshte mishavad
kar hay bishtari mesl taghir rang roozi ke yaddasht darad ham dar in function mitavanest anjam shavad ke 
moteasefane vaght nakardam
dar payan function setcolor agar gharar migeref va ba tarikh rooz set mishod rang roozi ke note darad taghir mikard  
*/




//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include "Calendar.h"
#include "Calendarp.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Date.h"
#include <conio.h>
#include <windows.h>
//#include<process.h>

Calendar::Calendar() {}

void Calendar::gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}

void Calendar::clrscr()
{
	system("cls");
}

void Calendar::Run()
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
				cout << "Invalid input." << endl;
				break;
			}
		}
	}
}

void Calendar::Draw()
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
	cout << "    " << day << "   " << Date::MonthNames[month - 1] << "   " << year << endl;
	gotoxy(20, 7);
	cout << "---------------------------";

	gotoxy(20, 8);
	for (int i = 0; i < sizeof Date::DayNames / sizeof Date::DayNames[0]; ++i) {
		cout << Date::DayNames[i] << " ";
	}
	
	int y = year - (month < 3);
	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
	int startingDay;
	int d = 1;
	startingDay = ((year + year / 4 - year / 100 + year / 400 + t[month - 1] + d) % 7);

	if ((month == 2)&&(startingDay!=0)) {
		startingDay = startingDay - 1;
	}

	if ((month == 1)) {
		startingDay = 6;
	}

	int dayCount = Date::MonthDays[month - 1];
	
	gotoxy(20, 9);
	for (int x = 0; x < startingDay; ++x) {
		cout << "    ";
	}

	int n=10;
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

void Calendar::NextDay() {
	currentDate.IncreaseDay();
}

void Calendar::PreviousDay() {
	currentDate.DecreaseDay();
}

void Calendar::Menu(int adad) {
	if (adad == '1') {
		Draw();
		Run();
	}
	if (adad == '2') {
		Calendarp c2;
		c2.Draw();
		c2.Run();
	}
}

void Calendar::Note() {
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


		if (line == "*") {
			note << line << endl;
			note.close();
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
		}
			//break;

		//note << line << endl;
	}
	//note.close();
}