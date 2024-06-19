#pragma once
#include <string>
class Person
{
public:
	Person(std::string name, int age);

	int Age() const { return age_; }
	std::string Name() const { return name_; }

	void Age(int age) {
		if (age >= 0 && age <= 150)
			age_ = age;
	}
	void Name(std::string name)
	{
		if (!name.empty() && name != "Steve")
			name_ = name;
	}

	void ItsMyBirthday();

private:
	int age_;
	std::string name_;
};

