#include "Person.h"
#include <iostream>

void Person::itsMyBirthday()
{
	++mAge;
	std::cout << "It's my birthday! I'm turning " << mAge << " years old today! WOOT! Let's have some cake.";
}
