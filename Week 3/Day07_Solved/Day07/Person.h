#pragma once
#include <string>

class Person
{
private:
	int mAge;
	std::string mName;

public:
	Person(int age, std::string name) : mAge(age), mName(name)
	{
	}
	void itsMyBirthday();

	int age() const
	{
		return mAge;
	}

	void age(int newAge)
	{
		if (newAge >= 0 && newAge <= 120)
			mAge = newAge;
	}

	std::string name() const
	{
		return mName;
	}

	void name(std::string newName) 
	{
		if (newName.length() > 0)
			mName = newName;
	}
};

