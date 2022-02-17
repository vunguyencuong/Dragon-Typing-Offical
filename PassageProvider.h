#pragma once
#include <fstream>
using namespace std;

class PassageProvider
{
	ifstream ifs;
	int range;
	string rootDir;

	PassageProvider();
	string readFromFile(string path);

	static PassageProvider* instance;
public:
	string random();
	static PassageProvider* getInstance();


};

