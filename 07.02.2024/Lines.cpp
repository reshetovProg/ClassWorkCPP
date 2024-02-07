#include "Lines.h"

Lines::Lines()
{
}

Lines::Lines(string str, char sep)
{
	string buf = "";
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == sep)
		{
			push_back(buf);
			buf = "";
			continue;
		}
		buf += str[i];		
	}
	push_back(buf);


}

void Lines::push_back(string str)
{
	string* buf = new string[countString + 1];
	for (int i = 0; i < countString; i++) {
		buf[i] = array[i];
	}
	buf[countString++] = str;
	delete[]array;
	array = buf;

}

int Lines::getCountString()
{
	return countString;
}

string* Lines::getArray()
{
	return array;
}
