#include "PassageProvider.h"
#include <random>
#include <string>
#include <iostream>

PassageProvider* PassageProvider::instance = nullptr;

PassageProvider::PassageProvider()
{
    rootDir = "./resources/passages/";
    range = 5;
    srand(std::time(nullptr));
}

string PassageProvider::readFromFile(string path)
{
    ifs.open(path);
    if (!ifs)
    {
        std::cout << "Error while open file" << std::endl;
        return "";
    }

    string s;

    while (!ifs.eof())
    {
        string temp;
        ifs >> temp;

        s += temp + " ";
   
    }

    ifs.close();
    return s;
}

string PassageProvider::random()
{
    int r = rand() % range + 1;

    return readFromFile(rootDir + std::to_string(r) + ".txt");
}

PassageProvider* PassageProvider::getInstance()
{
    if (instance == nullptr)
        instance = new PassageProvider();

    return instance;
}

