#pragma once
#include "Car.h"
#include <iostream>
using namespace std;
class FlyingCar : public Car
{
public:
	FlyingCar(int maxAltitude, int year, std::string make, std::string model)
		: Car(year, make, model)
	{
		cout << mModelYear;
	}
};

