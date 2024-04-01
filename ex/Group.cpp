#include "Group.h"

Group::Group(int maxCountStudent)
{
	this->uniqId = id++;
	this->maxCountStudents = maxCountStudent;
}

void Group::updateStudents()
{
	string fileName = to_string(uniqId) + ".csv";
	vector<string> studentsString = FileManager::readFile(fileName);
	students.clear();
	for (auto el : studentsString) {
		students.push_back(Student(el));
	}
}

void Group::addStudent(Student student)
{
	if(students.size()<maxCountStudents)
		students.push_back(student);
}

void Group::showInfo()
{
	cout << uniqId << " : " << endl;
	for (auto el : students) {
		cout << el.toString() << endl;
	}
}

void Group::save()
{
	vector<string> strings;
	for (auto el : students) {
		strings.push_back(el.toString());
	}
	string fileName = to_string(uniqId) + ".csv";
	FileManager::writeFile(fileName, strings);
}

int Group::id = 1;
