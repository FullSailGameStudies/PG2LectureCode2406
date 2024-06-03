#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

class Car
{
private:
	int mModelYear;
	std::string mMake;
	std::string mModel;

public:

	std::string vehicleInformation();

	Car() :mModelYear(0), mMake(""), mModel("") { }
	Car(int modelYear, std::string make, std::string model) :
		mModelYear(modelYear), mMake(make), mModel(model)
	{}
	Car(std::string csvData, char objDelim)
	{
		deserialize(csvData, objDelim);
	}

	void serialize(std::ostream& file, char objectDelimiter) const
	{
		file << mModelYear << objectDelimiter << mMake << objectDelimiter << mModel;
	}

	void deserialize(std::string csvData, char objectDelimiter)
	{
		std::string partStr;
		std::stringstream parts(csvData);

		std::getline(parts, partStr, objectDelimiter);
		mModelYear = std::stoi(partStr);

		std::getline(parts, mMake, objectDelimiter);

		std::getline(parts, mModel, objectDelimiter);
	}

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

