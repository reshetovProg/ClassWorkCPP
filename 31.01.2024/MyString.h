#pragma once
#include <iostream>
class MyString
{
private:
	char* str;
	int size;

public:
	MyString(const char arr[]);
	void show();
	bool empty();
	void clear();
	void append(const char arr[]);
	void append(const MyString& newString);
	void operator=(const char arr[]);
	int compare(const char arr[]);
	int compare(const MyString& newString);
	static int stoi(const char arr[]);

};

