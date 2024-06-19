#include "Person.h"
#include <iostream>

Person::Person(std::string name, int age) :
	name_(name)
	,age_(age)
{
}

void Person::ItsMyBirthday()
{
	++age_;
	std::cout << "It's my birthday!! I am " << age_ << " years old! dang.\n";
}


