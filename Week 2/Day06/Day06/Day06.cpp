// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>


enum class Weapon
{
    Sword=10, Axe=20, Spear=30, Mace=40
};


void Print(const std::map<std::string, double>& course)
{
    std::cout << "\n____DCU Grades____\n";
    for (auto& [student,grade] : course)
    {
        std::cout << std::setw(10) << std::left << student;
        std::cout << std::setw(3) << std::right << grade << "\n";
    }
}

int main()
{

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Removing a key and its value from a map  ]

        erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
        erase(key) -- returns the # of items removed

    */
    std::map<Weapon, int> dorasBackpack;
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    dorasBackpack[Weapon::Axe] = 3;

    size_t numberRemoved = dorasBackpack.erase(Weapon::Sword);
    if (numberRemoved > 0)
        std::cout << "The Swords were removed.\n";
    else
        std::cout << "Sword was not found in the map.\n";

    std::map<Weapon, int>::iterator found = dorasBackpack.find(Weapon::Axe);
    if (found != dorasBackpack.end())
    {
        auto nextIterator = dorasBackpack.erase(found);
        std::cout << "The Axes were removed.\n";
    }
    else
        std::cout << "Axe was not found in the map.\n";





    /*
        CHALLENGE 1:

                    print the students and grades below
                        use std::setw and std::left and std::right to format the output
                    ask for the name of the student to drop from the grades map
                        use std::getline to get the user's input
                    remove the student from the map
                    print message indicating what happened
                    if not found print an error message
                    else print the map again and print that the student was removed


    */
    srand((unsigned int)time(NULL));
    std::map<std::string, double> DCU;
    DCU["Bruce"] = rand() % 101;
    DCU["Dick"] = rand() % 101;
    DCU["Diana"] = rand() % 101;
    DCU["Alfred"] = rand() % 101;
    DCU["Clark"] = rand() % 101;
    DCU["Arthur"] = rand() % 101;
    DCU["Barry"] = rand() % 101;

    do
    {
        Print(DCU);

        std::cout << "Student to drop? ";
        std::string student;
        std::getline(std::cin, student);
        if (student.empty()) break;

        auto foundHero = DCU.find(student);
        if (foundHero == DCU.end())
            std::cout << student << " was not found. Try again.\n";
        else
        {
            std::cout << "Dropping " << student << ". Final grade was " << foundHero->second << "\n";
            DCU.erase(foundHero);
        }

    } while (true);
}