#include "Car.h"

int Car::numberOfCarsMade = 0;

//EVERY non-static methods have a 'hidden' parameter
//called 'this'
//non-static methods can access non-static AND static members
std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}
