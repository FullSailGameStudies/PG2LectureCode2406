#include "ThemeSong.h"
#include <iostream>


void ThemeSong::BatTheme(int numberOfNas)
{
	for (size_t i = 0; i < numberOfNas; i++)
	{
		std::cout << "na ";
	}
	std::cout << "BATMAN!\n";
}
