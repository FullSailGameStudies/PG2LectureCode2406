#pragma once
#include <string>

class Car
{
private:
	int mModelYear;
	std::string mModel;
	std::string mMake;

public:
	Car() : mMake("Ford"), mModel("A"), mModelYear(1908)
	{}

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model)
	{

	}
	std::string vehicleInformation();

	//getter (accessor)
	int modelYear() const
	{
		return mModelYear;
	}

	//setter (mutator)
	void modelYear(int newModelYear)
	{
		if (newModelYear > 1908 && newModelYear < 2100)
		{
			mModelYear = newModelYear;
		}
	}

protected:
};

