#pragma once
#include <iostream>
#include "Lines.h"
#include <string>
using namespace std;

class Student
{
private:
	int id;
	string firstName;
	string lastName;
	string group;
	int* marks;
	int countMarks;
public:
	Student(Lines line);
	void showInfo();

};


