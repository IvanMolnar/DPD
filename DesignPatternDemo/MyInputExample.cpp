#include "MyInputExample.h"



MyInputExample::MyInputExample(screenType st) : Input (st)
{
}


MyInputExample::~MyInputExample()
{
}

unsigned int MyInputExample::waitForInput()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD cNumRead;
	INPUT_RECORD irInBuf[128];

	while (true)
	{
		ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead);  // number of records read

		switch (irInBuf[0].EventType)
		{
		case KEY_EVENT:
			return irInBuf[0].Event.KeyEvent.uChar.AsciiChar;
		}
	}

	return 0;
}
