// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used 
            to separate the data when reading the file back in.

    */  
    std::string filePath = "myDataFile.csv";
    std::ofstream myFile(filePath);
    char delimiter = '*';
    myFile << 13 << delimiter << "Batman" << delimiter << true << delimiter << 13.7;
    myFile.close();


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

    */
    std::ifstream inputFile(filePath);
    std::string inputLine;
    std::getline(inputFile, inputLine);//NOTE: if the file has more than 1 line, you would need a loop
    inputFile.close();
    std::cout << inputLine << "\n";


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

    */
    std::vector<std::string> data;
    std::stringstream inputStream(inputLine);
    std::string placeHolder;
    while (std::getline(inputStream, placeHolder, delimiter))
    {
        data.push_back(placeHolder);
    }
    for (auto& item : data)
        std::cout << item << "\n";

    int number = std::stoi(data[0]);
    std::string name = data[1];
    bool isTrue = std::stoi(data[2]) == 1;
    double score = std::stod(data[3]);

    std::cout << number << " " << name << " " << isTrue << " " << score << "\n";



    /*

        CHALLENGE:
        
        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data. 
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';


    std::stringstream heroStream(multi);
    std::string heroCSV;
    while (std::getline(heroStream, heroCSV, collectionSeparator))
    {
        //std::cout << heroCSV << "\n";

        std::stringstream heroDataStream(heroCSV);
        std::string heroDataCSV;
        while (std::getline(heroDataStream, heroDataCSV, objectSeparator))
        {
            std::cout << heroDataCSV << "\t";
        }
        std::cout << "\n";
    }

}