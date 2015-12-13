#include <conio.h>
#include <iostream>

int getkb()
{
	unsigned key = 0;
	bool keyhit = false;

	while (!keyhit)
	{
		key = _getch();		
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
		key = _getche();		
		std::cout.put('\xA');
		if (key != 0)
		{
				keyhit = true;
		}
	}
	return key;
}

