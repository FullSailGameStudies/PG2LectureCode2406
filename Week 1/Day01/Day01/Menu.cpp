#include "Menu.h"

//A method DEFINITION
//add the class scope to tell the compiler 
//what class this method belongs to
void Menu::AddMenuItem(std::string menuItem)
{
	menu.push_back(menuItem);
}