#pragma once
#include <vector>
#include "MenuItem.h"
//class DECLARATION
//	what can the class DO (methods)
//  what describes the class (data/fields)
class Menu
{
public:
	//a DEFAULT ctor (constructor) is provided
	//by the compiler IFF (if and only if) you 
	//do not provide a ctor
	//if I create ANY ctor, the compiler version
	//is no longer created
	//Menu()//default ctor (no parameters)
	//{}
	Menu(std::vector<MenuItem> items);

private:
	std::vector<MenuItem> menuItems;
};

