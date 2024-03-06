
#include <iostream>
#include "Manager.h"
#include "ManagerGamePc.h"
#include "ManagerOfficePc.h"

int main()
{
    setlocale(LC_ALL, "");
    int result;
    std::cin >> result;
    Manager* m1 = nullptr;
    switch (result) {
    case 1:
        m1 = new ManagerGamePc;
        break;
    case 2:
        m1 = new ManagerOfficePc;
        break;
    }

    m1->release();


}
