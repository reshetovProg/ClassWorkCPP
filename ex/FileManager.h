#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class FileManager
{
public:
	static vector<string> readFile(string path);
	static void writeFile(string path, vector<string> str);
	static vector<string> split(string str, char div);
};

