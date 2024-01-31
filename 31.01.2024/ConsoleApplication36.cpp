#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    MyString str("4132654");
    str.show();
    //cout << str.empty()<<endl;
    //str.clear();
    //str.show();
    //cout << str.empty()<<endl;
    //str = "5672348382";
    //str.show();
    //str.append("6283746");
    //str.show();
    //MyString str2("41332654");
    //str.append(str2);
    //str.show();
    cout<<str.compare("4132654")<<endl;
    cout << str.compare("4132")<<endl;
    cout << str.compare("413265434")<<endl;

    int k = MyString::stoi("-2k34756");
    cout << k;
 



}
