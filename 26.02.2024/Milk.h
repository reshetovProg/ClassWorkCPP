#pragma once
#include "Product.h"
#include <string>
#include <iostream>
class Milk: public Product
{
private:
	static std::string img;
public:
	Milk(std::string name);
};

