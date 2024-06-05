#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	//a method DECLARATION
	// without the { }
	// end the line with a ;
	void AddMenuItem(std::string menuItem);

private:
	std::vector<std::string> menu;
};

