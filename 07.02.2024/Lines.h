#pragma once
#include "iostream"
using namespace std;

class Lines
{
private:
	string* array = nullptr;
	int countString=0;
public:
	Lines();
	Lines(string str, char sep);
	void push_back(string str);
	int getCountString();
	string* getArray();
};

