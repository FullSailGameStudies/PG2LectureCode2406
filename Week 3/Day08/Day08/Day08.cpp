// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "FlyingCar.h"
#include "Pistol.h"
#include "SpaceCar.h"
#include <vector>


void Printer()
{
	static int i = 0;
	std::cout << i++ << " ";
}

int main()
{
	for (size_t j = 0; j < 10; j++)
	{
		Printer();//0 1 2 3 4 5 6...9
	}
	FlyingCar martysRide(1985, "DeLorean", "DMC-12", 2000, 0);
	SpaceCar lukesRide(1985, "DeLorean", "DMC-13", 2000, 0);
	std::cout << martysRide.vehicleInformation() << "\n";
	std::cout << lukesRide.vehicleInformation() << "\n";

	//myRide is a separate object from martysRide
	Car myRide = martysRide;//??? COPIES only the Car parts of martysRide to myRide.
	myRide.vehicleInformation();//will call the Car's version

	//martysRide.vehicleInformation(&martysRide);
	//lukesRide.vehicleInformation(&lukesRide);
	Car::VehicleReport();
	/*
		╔═══════════════╗
		║  Inheritance  ║
		╚═══════════════╝

								╔═════════╗     ╔══════════╗
						 class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)



				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

	*/
	Pistol pew1(100, 50, 10, 2);
	Pistol pew2(100, 50, 10, 7);
	//pew2 = pew1 + pew2;







	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
		╔════════════════════════╗
		║  RUNTIME Polymorphism  ║
		╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/




	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	{
		int nummie = 5;//stack memory
		int* pNummie = &nummie;
		int& rNummie = nummie;

		//dynamic memory
		// = new then you're working in the heap
		//developers must clean up dynamic memory with "delete"
		int* pNumber = new int(5);//heap memory
		int* pNum2 = pNumber;//copies the memory address to pNum2
		delete pNumber;//frees the heap memory to be used for something else
		pNumber = nullptr;
		if (pNumber != nullptr) {}

		derived* pder1 = new derived("Gotham", 1);
		pder1->print();
		delete pder1;

		auto pDerived = std::make_unique<derived>("Gotham", 1);
		pDerived->print();
	}//pDerived is automatically deleted

	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Try to create some unique_ptrs to FlyingCar


	*/


	std::unique_ptr<FlyingCar> pFlying =
		std::make_unique<FlyingCar>(1985, "DeLorean", "DMC-12", 2000, 0);
	std::unique_ptr<Car> uCurrentRide = std::move(pFlying);//moves the ownership of the memory
	std::cout << "upcasting test: " << uCurrentRide->vehicleInformation();
	if (pFlying != nullptr)
		pFlying->vehicleInformation();

	std::vector<std::unique_ptr<Car>> garage;
	garage.push_back(std::move(uCurrentRide));
	garage.push_back(std::make_unique<SpaceCar>(1985, "DeLorean", "DMC-12", 2000, 0));
	garage.push_back(std::make_unique<Car>(1988, "Ford", "Mustang GT"));
	std::cout << "\n\nJay's Garage\n----------------\n";
	for (auto& car : garage)
	{
		std::cout << car->vehicleInformation() << "\n";
	}
	std::cout << "----------------\n";

	//UPCASTING. cast from a derived type to a base type
	//this is ALWAYS safe. why? b/c the derived is always a kind-of base
	FlyingCar* flCar = new FlyingCar(1985, "DeLorean", "DMC-12", 2000, 0);
	Car* myCurrentRide = flCar;//?? it points to the same object
	myCurrentRide->refuel();
	myCurrentRide->vehicleInformation();//which one gets called? Car's or FlyingCar's?
	//it will call the FlyingCar's version b/c FlyingCar OVERRODE the Car's version

	//SpaceCar lukesRide(1985, "DeLorean", "DMC-13", 2000, 0);

	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/
}

