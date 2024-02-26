#pragma once
#include "Product.h"
#include <string>
#include <iostream>
class Fish : public Product
{
private:
	static std::string img;
public:
	Fish(std::string name);

};

