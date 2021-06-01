#include "Specs.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::tuple<int, int> Specs::parseFromFile(const std::string file_path)
{
    std::ifstream myfile;
    std::string str; // file line iterator

    // constexpr std::string file_path = "../data/spec.txt";

    std::vector<std::pair<int, int>> data;

    // myfile.open("../data/sampdata.txt", std::ios::in); // smaller test data sample
    // myfile.open("../data/spec.txt", std::ios::in);
    myfile.open(file_path, std::ios::in);

    constexpr std::string startfileseq = "begin"; //from requirements file
    constexpr std::string endfileseq = "end";     //from requirements file
    constexpr std::string beginseq = "~~";        //from requirements file
    constexpr std::string endseq = "??";          //from requirements file
    constexpr std::string delimiter = "!-!";      //from requirements file

    std::string parsedata;
    bool doiter = false;

    if (myfile.is_open())
    {
        for (std::string line = ""; std::getline(myfile, str);)

        {
            if (str == startfileseq)
            {
                doiter = true; // setting the flag to be true for first found instance of 'begin'
            }
            if (doiter)
            {

                if (str.rfind(" ~~ ", 0) == 0) // parse line only for found pattern match
                {
                    std::string::size_type i = str.find(beginseq);
                    if (i != std::string::npos)
                    {
                        str.erase(i, beginseq.length()); // erase the ~~ from the beginning
                    }

                    std::string widthParsed = str.substr(0, str.find(delimiter));

                    std::string heightParsed = str.substr(str.find(delimiter) + 3).erase(str.length() - str.find("??") + 1, 2);

                    // std::cout << heightParsed << std::endl;

                    data.push_back(make_pair(stoi(widthParsed), stoi(heightParsed)));
                }
            }

            if (str == "end")
            {
                doiter = false; // setting the flag to be false for first found instance of 'end'

                std::cout << "Reached end, exiting parsing file." << std::endl;
            }
        }
        share

            //close the file
            myfile.close();
    }
    else
        std::cerr << "Unable to open file" << std::endl; // file opening error

    int width = 0, height = 0, i = 0;
    for (std::pair<int, int> a : data)
    {
        // std::cout << a.first << "  " << a.second << std::endl;
        if (height < a.second)
        {
            height = a.second;
        }
        width += a.first;
        i++;
    }
    width = width / i;

    std::cout << "Height is " << height << std::endl;
    std::cout << "Width is " << width << std::endl;

    std::cout << "Returning the height and width"<<std::endl;

    return std::make_tuple(width, height);
}


