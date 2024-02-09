#include "Product.h"

Product::Product(string name, float price)
{
	uniqId = id++;
	this->name = name;
	this->price = price;
}

string Product::getName()
{
	return name;
}

float Product::getPrice()
{
	return price;
}

void Product::showInfo()
{

	cout <<uniqId<<" - "<< name << " : " << price;
}

int Product::getId()
{
	return uniqId;
}

int Product::id = 0;
