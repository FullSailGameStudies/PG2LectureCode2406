// Day07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"
#include "Person.h"


/*              CLASSESS

			╔═════╗ ╔═════════╗
			║class║ ║SomeClass║
			╚═════╝ ╚═════════╝
				│          │
			 ┌──┘          │
		┌────▼─────┐   ┌───▼───┐
		│ Keyword  │   │ Class │
		│          │   │  Name │
		└──────────┘   └───────┘

		FIELDS - the data of the class

		METHODS - the behavior of the class (what the class can do)

		SPECIAL METHODS:
			Getters/Setters - the gatekeepers of the fields
			CONSTRUCTORS - the initializer of the class
			DESTRUCTORS - destroys allocated memory.





	╔══════════════════╗
	║ ACCESS MODIFIERS ║ - determines who can see it
	╚══════════════════╝
		public: EVERYONE can see it
		private: ONLY this class can see it  (default)
		protected: this class and all its descendent classes can see it




*/


int main()
{
	//created an instance of the Menu class
	std::vector<MenuItem> itemsToAdd;
	MenuItem burger("Florida Man Burger", "A burger with questionable items.", std::vector<std::string>{
		"Iguana meat", "Ghost Peppers", "bath salts"}, 21.99F);
	Menu kidsMenu(itemsToAdd);//calling a DEFAULT constructor here
	/*
		Lecture code: add a Car class

	*/





	/*
		╔════════╗
		║ FIELDS ║ - the data members of the class
		╚════════╝

		use mCamelCasingNamingConvention to name your fields in a C# class

		int mModelYear;

		Lecture code: add year, make, model fields to the car class

	*/





	/*
		╔═════════╗
		║ METHODS ║ - the member functions of the class -- the behavior of the class (what it can do)
		╚═════════╝

		non-static methods can access the fields/methods of the class
		static methods can only access the static members of the class

		EXAMPLE:
		void whoAmI()
		{
			std::cout << mName;
		}

		Lecture code: add a vehicleInformation method
	*/






	/*
		╔═════════════════╗
		║ Getters/Setters ║ - the gatekeepers (control access) of the fields
		╚═════════════════╝

		use camelCasingNamingConvention to name your getter/setter methods


		int modelYear() const  //const says the method can't modify anything
		{
			return mModelYear;  //provides access to the field's value
		}

		void modelYear(int year)
		{
			mModelYear = year;
		}

		Lecture code: add getters/setters for year, make, model fields to the car class
	*/




	/*
		╔══════════════╗
		║ CONSTRUCTORS ║ - the initializer of the class. Initialize the data of the class.
		╚══════════════╝

		RULES FOR CONSTRUCTORS...
		1) cannot have any return type, not even void
		2) must have the same name as the class

		HINT: use the ctor code snippet to provide a default contructor

		Car(int year, std::string make)
		{
		   mModelYear = year;
		   mMake = make;
		}

		Lecture code: add 2 ctors (default and non-default) to the car class
	*/



	/*
		CHALLENGE:

			Create a Person class.
			Right-Click the project and select "Add > Class..."


			Add an age field and a name field to the Person class


			Add Age getter/setter to provide access to the mAge field
			Add a Name getter/setter for the mName field


			Add a constructor to the Person class to initialize the age and name fields


			write an ItsMyBirthday method. increment age and print out a happy message.
	*/
	Person steev("Steev", 12);
	steev.Name("Stevia");
	steev.ItsMyBirthday();
	std::cout << "Hi. I am " << steev.Name() << " and I am " << steev.Age() << "!\n";


	/*
		╔══════════════╗
		║  STRUCTURES  ║ - light-weight data objects
		╚══════════════╝

		In C++, structs are just like classes EXCEPT members are public by default.

		Lecture code: add struct for ManufacturerDetails (Name, YearEstablished)
	*/

}