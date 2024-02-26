#include "Product.h"


Product::Product(std::string name)
{
	this->name = name;
}

void Product::getInfo()
{
	std::cout << type << " : " << name << std::endl;
}
