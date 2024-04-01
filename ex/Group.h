#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "FileManager.h"
using namespace std;

class Group
{
private:
	static int id;
	int uniqId;
	int maxCountStudents;
	vector<Student> students;
public:
	Group(int maxCountStudent);
	void updateStudents();
	void addStudent(Student student);
	void showInfo();
	void save();


};

