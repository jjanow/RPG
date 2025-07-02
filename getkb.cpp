#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <cstdio>

// Linux implementation of getch() and getche()
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int getche() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

#else
#include <conio.h>
#endif

#include <iostream>

int getkb()
{
	unsigned key = 0;
	bool keyhit = false;

	while (!keyhit)
	{
		key = getch();		
		std::cout.put('\xA');
		if (key != 0)
		{
				keyhit = true;
		}
	}
	return key;
}

int getkbe()
{
	unsigned key = 0;
	bool keyhit = false;

	while (!keyhit)
	{
		key = getche();		
		std::cout.put('\xA');
		if (key != 0)
		{
				keyhit = true;
		}
	}
	return key;
}

