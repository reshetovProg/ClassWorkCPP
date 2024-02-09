#pragma once
#include <iostream>
using namespace std;

class Product
{
private:
	static int id;
	int uniqId;
	string name;
	float price;
public:
	Product(string name, float price);
	string getName();
	float getPrice();
	void showInfo();
	int getId();

};



