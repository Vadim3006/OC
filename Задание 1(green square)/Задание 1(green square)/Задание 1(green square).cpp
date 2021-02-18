#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"

typedef BOOL(WINAPI* SETCONSOLEFONT)(HANDLE, DWORD);     // прототип недокументированый функции
SETCONSOLEFONT SetConsoleFont;
using namespace std;
const WORD colors[] =
{
0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B, 0x2B // синий 0x1A, голубой  0x3C, 0x2B зеленый,   ;
};

int main()
{

	//HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );//заголовок потока //ввода
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	// Tell the user how to stop
	SetConsoleTextAttribute(hstdout, 0xEC);
	cout << "Press any key to quit.\n";


	while (index < 7)
	{
		SetConsoleTextAttribute(hstdout, colors[index]);
		cout << "\t\t\t\t          \t\t\t\t" << endl;


		if (++index > sizeof(colors) / sizeof(colors[0]))
			break;
	}
	//FlushConsoleInputBuffer( hstdin ); // очистить буфер 


	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
	getchar();
	return 0;
}