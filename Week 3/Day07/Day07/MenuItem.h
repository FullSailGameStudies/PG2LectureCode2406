#pragma once
#include <string>
#include <vector>
class MenuItem
{
public:
	MenuItem(std::string name, std::string descr, std::vector<std::string> ingredients, float price);
	
	//getters (accessors) - provide access to the fields
	std::string GetName() const
	{
		return name_;
	}
	float Price() const { return price_; }

	//setters (mutators) - allow code to change the fields
	void SetName(std::string name)
	{
		if(!name.empty() && name.size() < 128)
			name_ = name;
		//name = name_;//BACKWARDS!
	}
	void Price(float price)
	{
		if (price > 0)
			price_ = price;
	}

private:
	//FIELDS (data of the class)
	//  m_sName  m_wsName  m_Name
	//  mName  _Name  Name_  name_
	std::string name_, description_;
	std::vector<std::string> ingredients_;
	float price_;

	void SampleMethod(int sampleParameter)
	{
		int localVariable;//camelCasing

	}
};

