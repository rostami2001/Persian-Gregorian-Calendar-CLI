/* dar main ebteday barname menu entekhab noe taghvim ra darim
* ba tavajoh be entekhab karbar taghvim marboote ba object hay marboot be class har
* taghvim farakhani mishavand
*/

#include <cstdlib>
#include<iostream>
#include "Calendar.h"
#include"Calendarp.h"
#include <fstream>
#include <conio.h>

using namespace std;

int main()
{
	system("Color 17");
	Calendar calendar;
	Calendarp calendarp;
	calendar.gotoxy(10, 10);
	cout << "Press the number of each calendar to select";
	calendar.gotoxy(12, 11);
	cout << "1-Gorgian     2-Persian" << endl;
	char ch = 'y';
	while (true)
	{
		int select;
		if (_kbhit())
		{
			select = _getch();
			if (select == '1') {
				calendar.gotoxy(10, 17);
				cout << "Press 'n' to next, 'p' to previous and 'q' to quit";
				calendar.gotoxy(10, 18);
				cout << "Press 'b' to go to the main menu";
				system("cls");
				calendar.Draw();
				calendar.Run();
				break;
			}
			if (select == '2') {
				calendarp.gotoxy(10, 17);
				cout << "Press 'n' to next, 'p' to previous and 'q' to quit";
				calendarp.gotoxy(10, 18);
				cout << "Press 'b' to go to the main menu";
				system("cls");
				calendarp.Draw();
				calendarp.Run();
				break;
			}	
		}
	}
	return 0;
}