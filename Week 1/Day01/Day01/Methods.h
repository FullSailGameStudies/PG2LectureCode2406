#pragma once
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> menu;

void AddMenuItem(std::string menuItem)
{
	menu.push_back(menuItem);
}
int NumberOfMenuItems()
{
	return static_cast<int>(menu.size());
}
void PrintMenu()
{
	std::cout << "\nG's Cafe\n--------\n";
	//ways to loop over a vector
	//1) for loop
	//for (int i = 0; i < menu.size(); i++)
	//{
	//	//i is used as the index into the vector
	//	std::string menuItem = menu.at(i);//copies the string from the vector
	//	std::cout << menuItem << "\n";
	//}

	//2) range-based for loop
	//& means a reference variable. does NOT make a copy.
	for (std::string& menuItem : menu)
	{
		std::cout << menuItem << "\n";
	}

	//3) for loop w/ iterators
	//an iterator is an object that knows how to move through a collection 
	//and access the items in the collection
	//begin() -- gives an iterator to the first item in the vector (like index 0)
	//end() -- gives an iterator to the item AFTER the last item (like size())
	//std::vector<std::string>::iterator
	//auto iterator = menu.begin();
	//for(; iterator != menu.end(); iterator++) 
	//{
	//	//iterators act like pointers
	//	//need to dereference the pointer. use *
	//	std::cout << *iterator << "\n";
	//}
}
void GlobalMethods()
{
	//void AddMenuItem(std::string menuItem);
	std::string item = "Sunny-side up eggs";
	AddMenuItem(item);
	AddMenuItem("Steak-n-cheese");
	AddMenuItem("hash browns");
	AddMenuItem("Coffee");
	AddMenuItem("Chicken-n-waffles");
	AddMenuItem("pancakes");

	int sizeOfMenu = NumberOfMenuItems();
	std::cout << sizeOfMenu << "\n";

	PrintMenu();

	//erase needs an ITERATOR!!!
	int index = 3;
	menu.erase(menu.begin() + index);
	//use a try-catch to prevent your app from crashes
	try
	{
		menu.erase(menu.end());//throws an exception
	}
	catch (const std::exception&)
	{

	}

	PrintMenu();
	std::cin.get();

	menu.clear();//will erase everything
}