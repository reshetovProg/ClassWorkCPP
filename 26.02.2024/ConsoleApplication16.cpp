#include <iostream>
#include <vector>
using namespace std;
#define random(a,b) a+rand()%(b+1-a)

#include "Product.h"
#include "Milk.h"
#include "Fish.h"
#include "Meet.h"
#include "Shelf.h"

string names[] = { "name1","name2","name3" };

int main()
{
    srand(time(NULL));
    Shelf shelf1(7);
    for (int i = 0; i < 4; i++) {
        shelf1.addProduct(new Milk(names[random(0, 2)]));
    }
    for (int i = 0; i < 3; i++) {
        shelf1.addProduct(new Meet(names[random(0, 2)]));
    }
    for (int i = 0; i < 2; i++) {
        shelf1.addProduct(new Fish(names[random(0, 2)]));
    }

    shelf1.showAllProducts();
    shelf1.getProductByIndex(2)->getInfo();
    cout << "after" << endl;
    shelf1.showAllProducts();
    shelf1.addProduct(new Fish(names[random(0, 2)]));
    cout << "after" << endl;
    shelf1.showAllProducts();
}
