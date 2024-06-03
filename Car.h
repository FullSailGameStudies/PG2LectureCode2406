#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class Car
{
private:
	int mModelYear;
	std::string mModel;
	std::string mMake;

public:
	void deserialize(std::string csvData, char delimiter)
	{
		//data format: year make model
		std::string outStr;
		std::stringstream sPart(csvData);
		std::getline(sPart, outStr, delimiter);
		mModelYear = std::stoi(outStr);//converts string to int
		std::getline(sPart, mMake, delimiter);
		std::getline(sPart, mModel, delimiter);
	}
	void serialize(std::ofstream outputFile, char delimiter)
	{
		outputFile << mModelYear << delimiter << mMake << delimiter << mModel;
	}

	std::string vehicleInformation();

	Car() { }
	Car(int modelYear=1908, std::string make = "Ford", std::string model = "A") :
		mModelYear(modelYear), mMake(make), mModel(model)
	{}

	const std::string& make() const
	{
		return mMake;
	}
	void make(std::string make)
	{
		mMake = make;
	}

	const std::string& model() const
	{
		return mModel;
	}
	void model(std::string model)
	{
		mModel = model;
	}

	int ModelYear() const  //const says the method can't modify anything
	{ 
		return mModelYear;  //provides access to the field's value
	}

	void ModelYear(int modelYear)
	{
		mModelYear = modelYear;
	}

	virtual void GetMSRP() = 0; //pure virtual function
};

