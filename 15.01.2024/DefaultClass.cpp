#include <iostream>
using namespace std;

/*создать класс Дробь
Объект данного класса должен состоять из
числителя и знаменателя в обязательном порядке
Реализовать метод вывода дроби в виде:
3/6
*/
class Fraction {
private:
	int total;
	int num;
	int denum;
public:
	Fraction(int num, int denum) {
		total = num / denum;			
		this->num = num % denum;
		this->denum = denum;
	}
	void show() {
		if(total==0)
			cout << num << "/" << denum<<endl;
		else
			cout <<total<<" "<< num << "/" << denum<<endl;
	}
};
/*
студент: номер группы, имя, ср. балл
методы:
выводить всю информацию о студенте
определять является ли студент отличником, хор
троечником или двоечник. (возвращает строку)
*/
class Student {
	string group;
	string name;
	float avg;
public:
	Student(string group, string name, float avg) {
		this->group = group;
		this->name = name;
		this->avg = avg;
	}
	void show() {
		cout << group << " : " << name << " : " << avg<<endl;
	}
	string getStatus() {
		if (avg > 4.6) return "A";
		if (avg > 3.6) return "B";
		if (avg > 2.6) return "C";
		else return "D";
	}
};


int main()
{
	//Student st1("34", "Pol", 4.5);
	//Student st2("345", "Pol2", 3.5);
	//Student st3("3", "Pol3", 2.5);
	//st1.show();
	//st2.show();
	//st3.show();
	//cout << st1.getStatus()<<endl;
	//cout << st2.getStatus() << endl;
	//cout << st3.getStatus() << endl;
	Fraction f1(4, 7);
	Fraction f2(23, 10);
	f1.show();
	f2.show();

}

