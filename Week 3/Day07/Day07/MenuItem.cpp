#include "MenuItem.h"

MenuItem::MenuItem(std::string name, std::string descr, std::vector<std::string> ingredients, float price) :
	 name_(name)
	,description_(descr)
	,ingredients_(ingredients)
	,price_(price)
{
}
