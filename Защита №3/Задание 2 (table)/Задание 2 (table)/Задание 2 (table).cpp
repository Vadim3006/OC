#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"

typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);     
SETCONSOLEFONT SetConsoleFont;
using namespace std;
const WORD colors[] =
{
0xF6
};

int main()
{


	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);



	while (index < 1 )
	{
		SetConsoleTextAttribute(hstdout, colors[index]);
		cout << "     Surname      ";
		cout << "     Group        " << endl;
		cout << "     Petrov       ";
		cout << "       1          " << endl;
		cout << "     Solovev      ";
		cout << "       2          " << endl;
		cout << "     Radivill     ";
		cout << "       3          " << endl;
		cout << "     Vrublevskiy  ";
		cout << "       4          " << endl;
		cout << "     Shelashen    ";
		cout << "       5          " << endl;
		cout << "     Kalistratov  ";
		cout << "       6          " << endl;


		if (++index > sizeof(colors) / sizeof(colors[0]))
			break;
	}

	


	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	getchar();
	return 0;
}