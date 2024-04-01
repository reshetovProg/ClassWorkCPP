#include "Student.h"
#include "string"

Student::Student(int id, string firstName, string secondName)
{
	this->id = id;
	this->firstName = firstName;
	this->secondName = secondName;
}

Student::Student(string str) {
	vector<string> buf = FileManager::split(str, ';');
	this->id = stoi(buf[0]);
	this->firstName = buf[1];
	this->secondName = buf[2];
}

string Student::toString()
{
	return to_string(id)+";"+firstName+";"+secondName+";";
}


