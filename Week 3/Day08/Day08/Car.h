#pragma once
#include <string>
#include <iostream>

class Car
{
public:
	//Car() : mMake("Ford"), mModel("A"), mModelYear(1908), mFuelLevel(0), mMaxFuelLevel(15)
	//{   }

	Car(int year, std::string make, std::string model)
		: mModelYear(year), mMake(make), mModel(model), mFuelLevel(0), mMaxFuelLevel(15)
	{
		numberOfCarsMade++;
	}
	virtual std::string vehicleInformation();

	//there is NO 'this'
	//static methods can ONLY access static data/methods
	static void VehicleReport()
	{
		std::cout << "We've made " << numberOfCarsMade << "!\n";
		//std::cout << std::to_string(mModelYear) + " " + mMake + " " + mModel;
	}

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
public:
	static int numberOfCarsMade;//static means shared by all Car instances

protected:
	int mModelYear;
	std::string mModel;
	std::string mMake;

	int mFuelLevel;
	int mMaxFuelLevel;

private:
};


