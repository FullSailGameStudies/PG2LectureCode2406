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


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */
    std::string path = "";// "C:\\temp\\2406\\";
    std::string fileName = "Sample.csv";
    std::string fullPath = path + fileName;

    //will create the file AT the path
    //will NOT create the path to the file
    //so, if any part of the path does not exists, it will fail
    std::ofstream outFile(fullPath);
    char delimiter = '|';
    if (outFile.is_open())
    {
        //<< insertion operator
        outFile << "Batman rules." << delimiter 
            << 5 << delimiter 
            << 13.7 << delimiter 
            << true;
    }
    else
    {
        std::cout << fullPath << " does not exists.\n";
    }
    outFile.close();


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */

    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        std::string line;
        std::getline(inFile, line);//reading until \n
        std::cout << line << "\n";

        //getline works with streams
        std::stringstream lineStream(line);
        std::string data;
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";
        std::getline(lineStream, data, delimiter);
        int iData = std::stoi(data);
        std::cout << iData << "\n";
        std::getline(lineStream, data, delimiter);
        double dData = std::stod(data);
        std::cout << dData << "\n";
        std::getline(lineStream, data, delimiter);
        bool bData = std::stoi(data) != 0;
        std::cout << bData << "\n";
        //???
        if (lineStream.eof())
            std::cout << "DONE READING\n";
        else
        {
            std::string endData;
            std::getline(lineStream, endData, delimiter);
            std::cout << endData << "\n";
        }

        while (std::getline(lineStream, data, delimiter))
        {

        }
    }
    else
    {
        std::cout << fullPath << " does not exists.\n";
    }
    inFile.close();


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





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
}