#pragma once
#include "Product.h"
#include <vector>
using namespace std;

class Shelf
{
	vector<Product*> products;
	int maxCount;
	int countProducts=0;
public:
	Shelf(int maxCount);
	void addProduct(Product* product);
	void showAllProducts();
	Product* getProductByIndex(int index);
};

