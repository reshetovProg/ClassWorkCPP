#include <iostream>
#include <vector>
#include "PathControl.h"

using namespace std;

int main()
{
    VersionController* v = nullptr;
    setlocale(0, "");
    while (true) {
        system("cls");
        cout << "Меню:\n1.Создать проект.\n2.Создать версию\n3.Список версий\n4.Откат\n5.Выход" << endl;
        cout << "Выберите пункт: ";
        int a;
        cin >> a;
        string arg;
        string arg2;
        switch (a)
        {
        case 1:
            system("cls");
            cout << "Введите директорию: ";
            cin >> arg;
            v = new VersionController(arg);
            break;
        case 2:
            system("cls");
            cout << "Введите имя проекта(без пробелов): ";
            cin >> arg;
            cout << endl << "Введите описание(без пробелов): ";
            cin >> arg2;
            v->createVersion(arg, arg2);
            break;
        case 3:
            system("cls");
            for (auto& i : v->getVersions()) {
                cout << i.second->getID() << ". " << i.second->getName() << " " << i.second->getDescription() << endl;
            }
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Введите номер версии: ";
            cin >> arg;
            if (!v->versionExists(stoi(arg))) { break; }
            v->returnToVersion(stoi(arg));
            break;
        case 5:
            return 0;
        default:
            continue;
        }
    }
}