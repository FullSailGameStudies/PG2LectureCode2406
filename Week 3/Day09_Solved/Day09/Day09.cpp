// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "static.h"
#include "abstract.h"

/*
Nested class
Abstract class
Static members
Final members
Friends
*/

int main()
{

    for (size_t i = 0; i < 10; i++)
    {
        demo();
    }

    Car myRide = Car::BuildCar(1988);
    Car::reporting();
    myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

    /*
    
        CHALLENGE:
        Add a static method to the Car class that returns an instance of the Car class.
    
    */
}