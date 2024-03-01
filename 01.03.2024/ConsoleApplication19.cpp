
#include <iostream>
#include "Singleton.h"
#include "Builder.h"
#include "Factory.h"
#define random(a,b) a+rand()%(b+1-a)

//#define SINGLETON
//#define BUILDER
//#define BUILDER_WITH_DIRECTOR
#define FACTORY_METHOD
using namespace std;


int main()
{
    srand(time(NULL));
#ifdef SINGLETON

    President* p1 = President::getInstance("Putin");
    President* p2 = President::getInstance("Medvedev");
    p1->showInfo();
    cout << endl;
    p2->showInfo();

#endif // SINGLETON

#ifdef BUILDER
    CarBuilder mercedesBuilder;
    CarBuilder ladaBuilder;
    CarDocumentationBuilder mercedesDocBuilder;
    CarDocumentationBuilder ladaDocBuilder;
    mercedesBuilder.setColor("red");
    mercedesBuilder.setModel("CLS");
    mercedesBuilder.setBrand("Mercedes");

    mercedesDocBuilder.setColor("red");
    mercedesDocBuilder.setModel("CLS");
    mercedesDocBuilder.setBrand("Mercedes");


    ladaBuilder.setColor("black");
    ladaBuilder.setEngine("1.8");
    ladaBuilder.setModel("Granta");
    ladaBuilder.setBrand("Lada");

    ladaDocBuilder.setColor("black");
    ladaBuilder.setEngine("1.8");
    ladaDocBuilder.setModel("Granta");
    ladaDocBuilder.setBrand("Lada");


    CarBuilder** builder = new CarBuilder*[2]{new CarBuilder, new CarBuilder};
    builder[0]->setColor("black");
    builder[0]->setEngine("1.8");
    builder[0]->setModel("Granta");
    builder[0]->setBrand("Lada");

    builder[1]->setColor("red");
    builder[1]->setModel("CLS");
    builder[1]->setBrand("Mercedes");

    Car* cars = new Car[10];
    for (int i = 0; i < 10; i++) {
        cars[i] = builder[random(0, 1)]->getResult();
    }

    for (int i = 0; i < 10; i++) {
        cars[i].show();
    }

#endif // BUILDER

#ifdef BUILDER_WITH_DIRECTOR
    CarBuilder* sportCarBuilder = new CarBuilder;
    CarDocumentationBuilder* sportCarDocBuilder = new CarDocumentationBuilder;
    CarBuilder* cityCarBuilder = new CarBuilder;
    CarDocumentationBuilder* cityCarDocBuilder = new CarDocumentationBuilder;

    Director director;
    director.createSportCar(sportCarBuilder, sportCarDocBuilder);
    director.createCityCar(cityCarBuilder, cityCarDocBuilder);

    Car car1 = sportCarBuilder->getResult();
    Car car2 = cityCarBuilder->getResult();

    CarDocumentation doc1 = sportCarDocBuilder->getResult();
    CarDocumentation doc2 = cityCarDocBuilder->getResult();

    cout << "__car1__"<<endl;
    car1.show();
    cout << "__car2__"<<endl;
    car2.show();
    cout << "__doc1__"<<endl;
    doc1.show();
    cout << "__doc2__"<<endl;
    doc2.show();
  



#endif

#ifdef FACTORY_METHOD
    Cookie** Cookies = new Cookie* [10];
    Factory** factories = new Factory * [2];
    factories[0] = new CocosCookieFactory;
    factories[1] = new ChocCookieFactory;

    for (int i = 0; i < 10; i++) {
        Cookies[i] = factories[random(0,1)]->createCookie();
    }

    for (int i = 0; i < 10; i++) {
        Cookies[i]->info();
    }


#endif


    
}
