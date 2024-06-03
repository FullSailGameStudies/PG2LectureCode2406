#pragma once
#include <string>

class Car
{
public:
	Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{	}
	std::string vehicleInformation();

	void refuel()
	{
		mFuelLevel = mMaxFuelLevel;
	}

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
	int mModelYear;
	std::string mModel;
	std::string mMake;

	int mFuelLevel;
	int mMaxFuelLevel;

private:
};


