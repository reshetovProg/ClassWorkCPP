#include "Shop.h"

int Shop::getIndexProductById(int id)
{
	for (int i = 0; i < countProducts; i++) {
		if (products[i]->getId() == id) return i;
	}
	return -1;
}

Shop::Shop(string name)
{
	this->name = name;
}

void Shop::buyProduct(Product product)
{
	Product** buf = new Product*[countProducts + 1];
	for (int i = 0; i < countProducts; i++) {
		buf[i] = products[i];
	}
	buf[countProducts++] = new Product(product);
	delete[]products;
	products = buf;
	outcome += product.getPrice();
}

Product* Shop::sellProduct(int id)
{
	int index = getIndexProductById(id);
	if (index == -1) return nullptr;
	Product* sellProduct = products[index];
	Product** buf = new Product * [countProducts - 1];
	for (int i = 0; i < index; i++) {
		buf[i] = products[i];
	}
	for (int i = index+1; i < countProducts; i++) {
		buf[i-1] = products[i];
	}
	income += products[index]->getPrice();
	delete[]products;
	products = buf;
	countProducts--;
	return sellProduct;
}

float Shop::getIncome()
{
	return 0.0f;
}

float Shop::getOutcome()
{
	return 0.0f;
}

void Shop::showInfo()
{
	cout << "Shop : " << name << endl;
	cout << "income: " << income;
	cout << " | outcome: " << outcome << endl;
	for (int i = 0; i < countProducts; i++) {
		products[i]->showInfo();
		cout << endl;
	}
}
