#pragma once
#include "FlyingCar.h"
class SpaceCar : public FlyingCar
{
public:
	SpaceCar(int year, std::string make, std::string model, float maxAlt, float stallSpeed)
		: FlyingCar(year,make,model,maxAlt,stallSpeed)
	{

	}

	std::string vehicleInformation();
};

