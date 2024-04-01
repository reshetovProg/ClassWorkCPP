#include <iostream>
using namespace std;
#include "Student.h"
#include "FileManager.h"
#include "Group.h"

/*
Есть школа в которой существуют группы.
Данные о доступных группах и студентах находятся в файле csv
записаны они в следующем виде:
№ группы; max количество человек; профиль

Профиль может быть либо phisics либо lingvo

Реализовать генерацию n-го количества групп.
! Номера групп должны быть уникальны.
Добавить возможность удаления групп из списка.
Все изменения записываются в файл.

В группах должны присутствовать студенты.
Студенты тоже должны быть записаны в файле, который будет
называться также как и группа.
! Количество студентов в группе не должно превышать
максимально допустимое.
Студенты записаны в сл. виде:
№ студента(уникальный для группы); имя; фамилия;
*/

int main()
{
    Student st1(1, "Alex", "Smirnov");
    Student st2(2, "Alex2", "Smirnov2");
    vector<string> students;
    students.push_back(st1.toString());
    students.push_back(st2.toString());
    FileManager::writeFile("group1.txt", students);
    vector<string> read = FileManager::readFile("group1.txt");
    //for (auto el : read) {
    //    cout << el << endl;
    //}
    vector<string> buf = FileManager::split(students[0], ';');
    for (auto el : buf) {
        cout << el << " : ";
    }
    Group group(3);
    group.updateStudents();
    group.showInfo();
}

