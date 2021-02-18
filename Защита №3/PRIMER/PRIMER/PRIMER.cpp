#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"


int main()
{

	HANDLE consoleOutput;
	COORD cursorPos;

	// Получаем хэндл консоли 
	consoleOutput = GetStdHandle(/*STD_OUTPUT_HANDLE*/2);

	// Задаем координаты курсора и перемещаем курсор
	cursorPos.X = 30;
	cursorPos.Y = 3;
	SetConsoleCursorPosition(consoleOutput, cursorPos);

	// Выводим строку
	printf("Test string at position (30, 3)");
}

