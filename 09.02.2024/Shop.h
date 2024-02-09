#pragma once
#include <iostream>
#include "product.h"
using namespace std;

class Shop
{
private:
	string name;
	float income=0;
	float outcome=0;
	Product** products;
	int countProducts=0;

	int getIndexProductById(int id);

public:
	Shop(string name);
	void buyProduct(Product product);
	Product* sellProduct(int id);
	float getIncome();
	float getOutcome();
	void showInfo();
};

