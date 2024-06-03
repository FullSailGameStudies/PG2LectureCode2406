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
	void serialize(std::ofstream& outputFile, char delimiter)
	{
		outputFile << mModelYear << delimiter << mMake << delimiter << mModel;
	}

	std::string vehicleInformation();

	Car() :mModelYear(0), mMake(""), mModel("") { }
	Car(std::string csvData, char delim)
	{
		deserialize(csvData, delim);
	}
	Car(int modelYear, std::string make, std::string model) :
		mModelYear(modelYear), mMake(make), mModel(model)
	{}

	int ModelYear() const  //const says the method can't modify anything
	{ 
		return mModelYear;  //provides access to the field's value
	}

	void ModelYear(int modelYear)
	{
		mModelYear = modelYear;
	}

	const std::string& Make() const
	{
		return mMake;
	}
	void Make(std::string make)
	{
		mMake = make;
	}

	const std::string& Model() const
	{
		return mModel;
	}
	void Model(std::string model)
	{
		mModel = model;
	}
};

