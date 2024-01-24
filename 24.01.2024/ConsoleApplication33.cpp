#include <iostream>
#include <string>
#define random(a,b) a+rand()%(b+1-a)
using namespace std;
//
//class Student;
//
//class StudentList {
//    Student* students = nullptr;
//    int countOfStudent;
//
//public:
//    void addStudent(Student newStudent) {
//        Student* buf = new Student[countOfStudent + 1];
//        for (int i = 0; i < countOfStudent; i++) {
//            buf[i] = students[i];
//        }
//        buf[countOfStudent++] = newStudent;
//        delete[]students;
//        students = buf;
//        
//    }
//
//
//    void removeMarkByIndex(int index) {
//
//        if (countOfStudent == 0 || index < 0 || index > countOfStudent - 1) return;
//        Student* buf = new Student[countOfStudent - 1];
//        for (int i = 0; i < index; i++) {
//            buf[i] = students[i];
//        }
//        for (int i = index + 1; i < countOfStudent; i++) {
//            buf[i - 1] = students[i];
//        }
//        delete[]students;
//        students = buf;
//        countOfStudent--;
//
//    }
//
//    void showAll() {
//        for (int i = 0; i < countOfStudent; i++) {
//            cout<<students->toString()<<endl;
//        }
//    }
//};
//
//class Student {
//    static int id;
//    int uniqId;
//    string name = "noname";
//    int* marks = nullptr;
//    int countMarks = 0;
//
//public:
//    Student() {};
//    Student(string name) {
//        uniqId = id++;
//        this->name = name;
//    }
//
//    void addMark(int mark) {
//        if (mark > 1 && mark < 6) {
//            int* buf = new int[countMarks + 1];
//            for (int i = 0; i < countMarks; i++) {
//                buf[i] = marks[i];
//            }
//            buf[countMarks++] = mark;
//            delete[]marks;
//            marks = buf;
//        }
//    }
//
//
//    void removeMarkByIndex(int index){
//
//        if (countMarks==0 || index < 0 || index > countMarks - 1) return;
//        int* buf = new int[countMarks - 1];
//        for (int i = 0; i < index; i++) {
//            buf[i] = marks[i];
//        }
//        for (int i = index + 1; i < countMarks; i++) {
//            buf[i - 1] = marks[i];
//        }
//        delete[]marks;
//        marks = buf;
//        countMarks--;
//           
//    }
//
//    string toString() {
//        string marksStr = "";
//        for (int i = 0; i < countMarks; i++) {
//            marksStr += to_string(marks[i])+" ";
//        }
//        return "id: " + to_string(uniqId) + ", name: "
//            + name + ", marks: "+ marksStr;
//    }
//
//};
//
//int Student::id = 0;

class Foo {
    int number;
    int* ar = nullptr;
    int count = 0;
public:
    Foo(Foo& foo) {
        this->number = foo.number;
        this->count = foo.count;
        ar = new int[count];
        for (int i = 0; i < count; i++) {
            ar[i] = foo.ar[i];
        }

    }
    Foo(int number) {
        this->number = number;
    }
    void addMark(int mark) {
        if (mark > 1 && mark < 6) {
            int* buf = new int[count + 1];
            for (int i = 0; i < count; i++) {
                buf[i] = ar[i];
            }
            buf[count++] = mark;
            delete[]ar;
            ar = buf;
        }
  
    }

    void changeMarkByIndex(int index, int num) {
        ar[index] = num;
    }

    void showInfo() {
        cout <<"number: "<< number << " count : " << count<<" :: ";
        for (int i = 0; i < count; i++) {
            cout << ar[i] << " ";
        }
        cout << endl;
    }

    void operator = (Foo& foo) {
        this->number = foo.number;
        this->count = foo.count;
        ar = new int[count];
        for (int i = 0; i < count; i++) {
            ar[i] = foo.ar[i];
        }

    }


};

int main()
{
   /* Student st1("Pol");
    Student st2("Tom");

    for (int i = 0; i < 10; i++)
        st1.addMark(random(2, 5));
    cout<<st1.toString()<<endl;
    st1.removeMarkByIndex(3);
    cout << st1.toString() << endl;
    for (int i = 0; i < 10; i++)
        st1.removeMarkByIndex(0);
    cout << st1.toString() << endl;

    StudentList list1;
    list1.addStudent(st1);
    list1.addStudent(st2);
    list1.showAll();*/
    Foo foo(12);
    for (int i = 0; i < 5; i++) {
        foo.addMark(random(2, 5));
    }
    foo.showInfo();
    Foo foo2 = foo;
//    foo2 = foo;
    foo2.showInfo();
    foo.changeMarkByIndex(2, 123);
    foo.showInfo();
    foo2.showInfo();


    
}
