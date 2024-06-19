#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	FlyingCar(int year, std::string make, std::string model, float maxAlt, float stallSpeed) :
		Car(year, make, model)
		,maxAltitude_(maxAlt)
		,stallSpeed_(stallSpeed)
	{
		//do NOT do what the base ctor is doing
		//REUSE, not duplicate
		//mModelYear = year;
	}

	float MaxAltitude() const { return maxAltitude_; }
	float StallSpeed() const { return stallSpeed_; }
	
private:
	float maxAltitude_, stallSpeed_;
};

