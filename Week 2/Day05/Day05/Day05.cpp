// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

/// <summary>
/// Linearly searches a vector for an item.
/// </summary>
/// <param name="searchVector">what am I searching in</param>
/// <param name="searchNumber">what am I searching for</param>
/// <returns></returns>
int LinearSearch(
    /* what am I searching in*/
    const std::vector<int>& searchVector,
    /* what am I searching for*/
    int searchNumber
)
{
    int foundIndex = -1;//not found
    for (size_t i = 0; i < searchVector.size(); i++)
    {
        if (searchNumber == searchVector.at(i))
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

void PrintGrades(const std::map<std::string, double>& course)
{
    std::cout << "\n\nPG2 2406 (June)\n";
    for (auto& [student,grade] : course)
    {
        std::cout << std::setw(13) << std::left << student;
        std::cout << std::setw(7) << std::right << grade;
        std::cout << "\n";
    }
}

//typedef std::map<std::string, float>::iterator menuIter;
int main()
{
    std::vector<int> nums{ 1,2,3,4,5 };
    int number = 10;
    int findIndex = LinearSearch(nums, number);
    if (findIndex == -1)
    {
        std::cout << number << " was not found.\n";
    }
    else
    {
        std::cout << number << " was found at index " << findIndex << "\n";
    }
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

        There are 2 ways to add items to a Map:
        1) using the insert method.
        2) using [key] = value
    */
    
    std::map<std::string, float> menu;
    menu["Catfish"] = 12.99F;
    std::string item = "Carp";
    menu[item] = 5.99F;
    menu[item] = 7.99F;//?? overwrites.

    std::pair<std::string, float> itemToInsert =
        std::make_pair("Salmon", 15.99F);
    std::pair<std::map<std::string,float>::iterator,bool> wasInserted = 
        menu.insert(itemToInsert);//does NOT overwrite
    //pair: first, second
    if (wasInserted.second)
        std::cout << "The item was inserted.\n";
    else
        std::cout << "The item was already in the map.\n";
    std::cout << "The item costs " << wasInserted.first->second << "\n";

    size_t size;
    std::cout << "\nPG2 Cafe\n";
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        std::string name = iter->first;//key
        float price = iter->second;//value
        std::cout << std::setw(10) << std::left << name << " " 
            << std::setw(7) << std::right << price << "\n";
    }
    std::cout << "\nPG2 Cafe\n";
    for (auto& item : menu)
    {
        std::string name = item.first;
        float price = item.second;
        std::cout << std::setw(10) << std::left << name << " "
            << std::setw(7) << std::right << price << "\n";
    }
    std::cout << "\nPG2 Cafe\n";
    for (const auto& [menuItem,menuPrice] : menu)
    {
        //menuPrice += 5;
        std::cout << std::setw(10) << std::left << menuItem << " "
            << std::setw(7) << std::right << menuPrice << "\n";
    }

    std::string itemToFind = "nuggies";
    //find returns...
    //  the end() if NOT found
    //  the iterator to the (key,value) pair if found
    std::cout << menu[itemToFind] << "\n";//will add the item!!
    auto foundItem = menu.find(itemToFind);
    if (foundItem != menu.end())
    {
        float price = foundItem->second;
        //menu[itemToFind] = price * 1.5;
        foundItem->second *= 1.5;
        std::cout << itemToFind << " used to costs " << price << "\n";
        std::cout << "Now it costs " << foundItem->second << "!! Thanks Putin!\n";

    }
    else
        std::cout << itemToFind << " is not on the menu. Try McDonald's!\n";


    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE 2:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */

    srand(time(NULL));
    std::vector<std::string> students{
    "Dylan", "Kyle", "Adrian", "Luke", "Luis",
    "Cy", "Ryan", "Harrison", "Gareth", "Sam",
    "Amirah", "Breanne", "Harry", "Jeremy",
    "Lor", "Patrick", "Pedro", "Quilliah",
    "Rebekah", "Roxythe", "Tyrone" };
    std::map<std::string, double> grades;
    for (auto& student : students)
    {
        //grades[student] = rand() % 10001 / 100.0;

        //or use the insert method
        double grade = rand() % 10001 / 100.0;
        auto studentInserted = grades.insert(std::make_pair(student, grade));
        if (!studentInserted.second)
        {
            std::cout << student << " is already in the course.\n";
        }
    }

    
    do
    {
        PrintGrades(grades);

        std::cout << "\nStudent to find: ";
        std::string studentName;
        std::getline(std::cin, studentName);
        if (studentName.size() == 0) break;
        studentName[0] = std::toupper(studentName[0]);
        auto foundStudent = grades.find(studentName);
        if (foundStudent == grades.end())
            std::cout << studentName << " is not in the course.\n";
        else
            std::cout << studentName << " has a grade of " << foundStudent->second << "\n";

    } while (true);


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}