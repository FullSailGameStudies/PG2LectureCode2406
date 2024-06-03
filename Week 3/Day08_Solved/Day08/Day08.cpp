// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "FlyingCar.h"
#include <vector>
#include "Pistol.h"

int main()
{
	/*
		Inheritance

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


		CHALLENGE:

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

	*/
	FlyingCar jetsons(5000, 2050, "Tesla", "XPlane");


	/*

		COMPILE-TIME Polymorphism

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters



		CHALLENGE:
			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*

		COMPILE-TIME Polymorphism

		Operator Overloading
		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.

	*/






	/*

		RUNTIME Polymorphism

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



		CHALLENGE:
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


		To maintain the original object, we need a pointer though.
		If not, then we're just calling the copy constructor of the base class
		and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can UPCAST by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move

	*/
	derived der1("Gotham", 1);//stack instance
	der1.print();
	base b1 = der1;//COPIED der1 to a new object, b1.
	b1.print();

	std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 1);
	pDerived->print();


	std::unique_ptr<base> pBase = std::move(pDerived);//upcasting. ALWAYS safe


	/*

		CHALLENGE:
		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/
	std::vector<std::unique_ptr<Weapon>> backpack;

	backpack.push_back(std::make_unique<Weapon>(rand(), rand()));
	backpack.push_back(std::make_unique<Weapon>(rand(), rand()));
	backpack.push_back(std::make_unique<Weapon>(rand(), rand()));
	backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
	backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
	backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
	backpack.push_back(std::make_unique<Pistol>(rand(), rand(), rand(), rand()));
	std::cout << "\n\n---Weapons---\n";
	for (auto& weapon : backpack)
		weapon->showMe();
}

