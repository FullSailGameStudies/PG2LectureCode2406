// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>


enum class Weapon
{
    Sword, Axe, Spear, Mace
};

//O(N) - linear.
int IndexOf(const std::vector<int>& numbers, int numberToFind)
{
    int foundIndex = -1;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == numberToFind)
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int index = IndexOf(numbers, searchNumber);
    if (index == -1)
        std::cout << searchNumber << " was not found.\n";
    else
        std::cout << searchNumber << " was found at index " << index << ".\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys. 
            TValue is a placeholder for the type of the values.

        When you want to create a map variable, 
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionaruy:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;

    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Axe, 5));
    if (inserted.second == false)
        std::cout << "The key was already in the map. \n";
    else
        std::cout << "The key was added.\n";

    dorasBackpack[Weapon::Sword] = 10;
    dorasBackpack[Weapon::Sword] = 4;//overwrites 10 with 4


    /*
        CHALLENGE 2:

            Create a map that stores names (string) and grades (doubles). 
            Call the variable grades.
            Add students and grades to your map.

    */
    std::map<std::string, double> grades;
    auto gradesInserted = grades.insert(std::make_pair("Bruce", rand() % 101));
    if (gradesInserted.second == false)
        std::cout << "The student was already in the course. \n";
    else
        std::cout << "The student was added.\n";
    grades["Clark"] = rand() % 101;
    grades["Diana"] = rand() % 101;
    grades["Arthur"] = rand() % 101;






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (const auto& [key, value] : dorasBackpack)
    {
        switch (key)
        {
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        default:
            break;
        }
        std::cout << value << "\n";
    }


    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */
    std::cout << "----GRADES----\n";
    for (const auto& [student, grade] : grades)
    {
        std::cout << student << ": " << grade << "\n";
    }











    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    auto weaponFound = dorasBackpack.find(Weapon::Mace);
    if (weaponFound != dorasBackpack.end())
        std::cout << "Dora found " << weaponFound->second << " Maces\n";
    else
        std::cout << "Dora did not find any maces.\n";



    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */
    std::string studentName = "Bruce";
    auto studentFound = grades.find(studentName);
    if (studentFound != grades.end())
        std::cout << studentName << " has a grade of " << studentFound->second << ".\n";
    else
        std::cout << studentName << " was not in the course.\n";









    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an existing value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Sword] = 15;







    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
    grades[studentName] = std::min<double>(100, grades[studentName] + 5);
    std::cout << "The grade for " << studentName << " is now " << grades[studentName] << ".\n";
}