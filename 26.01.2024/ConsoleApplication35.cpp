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
	int countMarks = 0;
public:
	Student() {
		name = names[random(0, countNames - 1)];
		uniqId = id++;
	}
	Student (Student& st): Student() {
	
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}

	~Student() {
		if (marks != nullptr) delete[] marks;
	}

	void operator = (Student& st) {
		name = st.name;
		countMarks = st.countMarks;
		marks = new int[countMarks];
		for (int i = 0; i < countMarks; i++) {
			marks[i] = st.marks[i];
		}
	}

	void addMark(int mark) {
		int* buf = new int[countMarks + 1];
		for (int i = 0; i < countMarks; i++) {
			buf[i] = marks[i];
		}
		buf[countMarks++] = mark;
		delete[]marks;
		marks = buf;
	}

	void changeMark(int index, int mark) {
		if(index>=0 &&index<countMarks){
			marks[index] = mark;
		}
	}
	
	

	void showInfo() {
		cout << uniqId << " : " << name<<" : ";
		for (int i = 0; i < countMarks; i++) {
			cout << marks[i] << " ";
		}
		cout << endl;
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
	Student** students;
	int countStudents;
public:
	Group() {
		this->countStudents = 0;
		uniqId = GroupName::getUniqGroupName();
		if (uniqId == "") cout << "достигнут предел групп";
	}

	int getCountStudents() {
		return countStudents;
	}

	void showInfo() {
		if (uniqId!="") cout << uniqId<<" "<<endl;
		for (int i = 0; i < countStudents; i++) {
			students[i]->showInfo();
		}
	}



	void addStudent(Student& st) {
		if (this->countStudents == 5) {
			cout << "превышен допустимый предел количества студентов";
			return;
		}
		Student** buf = new Student*[countStudents + 1];
		for (int i = 0; i < countStudents; i++) {
			buf[i] = students[i];
		}
		for (int i = 0; i < countStudents; i++) {
			students[i] = nullptr;
		}
		delete[]students;

		buf[countStudents] = new Student(st);
		
		countStudents++;
		students = buf;
	}

	Student* getStudentByIndex(int index) {
		return students[index];
	}



};



int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	

	int const countGroups = 7;
	Group** groups = new Group*[countGroups];
	for (int i = 0; i < 7; i++) {
		groups[i] = new Group();
	}
	for (int i = 0; i < 30; i++) {
		
		int indexStudentInGroup = random(0, countGroups - 1);
		while (groups[indexStudentInGroup]->getCountStudents()!=5) {
			Student st;
			for (int j = 0; j < 4; j++) {
				st.addMark(random(2, 5));
			}
			groups[indexStudentInGroup]->addStudent(st);
		}

	}
	for (int i = 0; i < countGroups; i++) {
		groups[i]->showInfo();
	}

	/*cout << "test uno student: " << endl;
	groups[0].showInfo();
	groups[0].getStudentByIndex(0)->changeMark(0, 12);
	groups[0].showInfo();*/

	



}
