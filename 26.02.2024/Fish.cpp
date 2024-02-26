#include "Fish.h"
Fish::Fish(std::string name) :
	Product(name)
{
	type = "fish";
}

std::string Fish::img = "Fish.png";