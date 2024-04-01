#pragma once
#include <iostream>
#include <vector>
#include "FileManager.h"
using namespace std;

class Student
{
private:
	int id;
	string firstName;
	string secondName;
public:
	Student(int id, string firstName, string secondName);
	Student(string str);
	string toString();

};

