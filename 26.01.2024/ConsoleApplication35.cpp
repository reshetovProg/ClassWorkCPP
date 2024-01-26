#include <iostream>
#include <string>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)

const int countNames = 5;
const string names[] = { "Олег", "Паша","Коля","Вика", "Оля" };

class Student {
	static int id;
	int uniqId;
	string name;
	int* marks = nullptr;
public:
	Student() {
		name = names[random(0, countNames - 1)];
		uniqId = id++;
	}

	void showInfo() {
		cout << uniqId << " : " << name << endl;
	}

};
int Student::id = 0;

struct GroupName {
	static int num;
	static char alpha;
public:
	static string getUniqGroupName() {
		if (num == 3) return "";
		int numPrev = num;
		char alphaPrev = alpha;
		
		if (alpha == 'Д') {
			alpha = 'А';
			num += 1;
		}
		else alpha++;
		
		return to_string(numPrev) + alphaPrev;
	}
};
int GroupName::num=1;
char GroupName::alpha='А';

class Group {
	
	string uniqId;
	Student* students;
	int countStudents = 0;
public:
	Group() {
		uniqId = GroupName::getUniqGroupName();
		if (uniqId == "") cout << "достигнут предел групп";
	}

	void showInfo() {
		if (uniqId!="") cout << uniqId<<" "<<endl;
		for (int i = 0; i < countStudents; i++) {
			students[i].showInfo();
		}
	}

	bool addStudent(Student st) {
		if (countStudents == 5) {
			cout << "превышен допустимый предел количества студентов";
			return false;
		}
		Student* buf = new Student[countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		buf[countStudents++] = st;
		//delete[]students;
		students = buf;
		return true;
	}



};



int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int const countGroups = 7;
	Group* groups = new Group[countGroups];
	for (int i = 0; i < 30; i++) {
		Student st;
		while (!groups[random(0, countGroups - 1)].addStudent(st));
	}
	for (int i = 0; i < countGroups; i++) {
		groups[i].showInfo();
	}
	

}
