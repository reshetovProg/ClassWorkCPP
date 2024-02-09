#include <iostream>
using namespace std;

#include "Product.h"
#include "Shop.h"

int main()
{
    Product product1("banana", 120);
    cout << product1.getName() << ":" << product1.getPrice();
    cout << endl;
    Product product2("mandarine", 300);
    product2.showInfo();
    cout << endl;

    Shop shop("5-ka");
    shop.buyProduct(product1);
    shop.buyProduct(product2);
    shop.showInfo();
    shop.sellProduct(0)->showInfo();
    shop.showInfo();


}
