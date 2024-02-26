#pragma once
#include "Product.h"
#include <string>
#include <iostream>
class Meet : public Product
{
private:
	static std::string img;
public:
	Meet(std::string name);

};

