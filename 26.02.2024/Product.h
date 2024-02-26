#pragma once
#include <string>
#include <string>
#include <iostream>

class Product
{
protected:
	std::string name;
	std::string type;


public:
	Product(std::string name);
	void getInfo();
};

