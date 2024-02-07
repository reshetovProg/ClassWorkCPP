#include "Student.h"

Student::Student(Lines line)
{
	string* array = line.getArray();

	id = stoi(array[0]);
	firstName = array[1];
	lastName = array[2];
	group = array[3];
	Lines marksLine(array[4], ',');
	marks = new int[marksLine.getCountString()];
	string* marksStr = marksLine.getArray();
	for (int i = 0; i < marksLine.getCountString(); i++) {
		marks[i] = stoi(marksStr[i]);
	}
	countMarks = marksLine.getCountString();

}

void Student::showInfo()
{
	cout << id << " : " <<
		firstName << " " <<
		lastName << " " <<
		group << " : ";
	for (int i = 0; i < countMarks; i++) {
		cout << marks[i] << " ";
	}
	cout << endl;
}
