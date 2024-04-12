#include <iostream>
#include <vector>
#include <ostream>
using namespace std;
/*
2. Используя полиморфизм реализовать разных животных
умеющих издавать звуки.
*/

class Animal {
public:
    void virtual makeSound() = 0;
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "miau";
    }
};
class Dog : public Animal {
public:
    void makeSound() {
        cout << "wow";
    }
};
class Cow : public Animal {
public:
    void makeSound() {
        cout << "muu";
    }
};

/*

3. Используя разные интерфейсы реализовать средства передвижения
которые должны уметь летать либо плавать либо ездить либо
комбинировать данные возможности.
*/

class Swimming {
public:
    void swim() {
        cout << "swim"<<endl;
    }
};
class Driving {
public:
    void drive() {
        cout << "drive" << endl;
    }
};
class Flieng {
public:
    void fly() {
        cout << "fly" << endl;
    }
};

class Ship : public Swimming {};

class Car: public Driving{};

class Aeroplane: public Flieng{};

class Hydroplan: public Flieng, public Swimming{};


/*
1. Используя переопределение опреаторов 
реализовать работу с деньгами.
Есть отдельно рубли и копейки. 
Необходимо уметь добавлять сумму и уменьшать сумму
на заданное количество денег.
*/

class Money {
private:
    int rub;
    int kop;
public:
    Money() {};
    Money(int rub, int kop) {
        this->rub = rub;
        this->kop = kop;
        this->rub += this->kop / 100;
        this->kop %= 100;
    }
    Money operator +(Money money) {
        Money newMoney;
        newMoney.rub = rub + money.rub;
        newMoney.kop = kop + money.kop;
        newMoney.rub += newMoney.kop / 100;
        newMoney.kop %= 100;
        return newMoney;
    }
    void showMoney() {
        cout << rub << "." << kop;
    }
    friend ostream& operator <<(ostream& out, Money& money) {
        out << money.rub << "." << money.kop;
        return out;
    }
};

class City {
    string name;
    string region;
    int countOfPeople;
public:
    City(string name, string region, int countOfPeople) {
        this->name = name;
        this->region = region;
        this->countOfPeople = countOfPeople;
    }
    string getName() {
        return name;
    }
    int getCountOfPeople() {
        return countOfPeople;
    }
    friend ostream& operator <<(ostream& out, City& city) {
        out << city.name << " : " << city.region<<" : "<<city.countOfPeople<<endl;
        return out;
    }
};

class CityDatabase {
    vector<City> cities;
public:
    void addCity(City city) {
        cities.push_back(city);
    }
    City findByName(string name) {
        for (auto el : cities) {
            if (el.getName() == name) return el;
        }
        throw "not found";
    }
    void sortByCountOfPeople() {
        for (int i = 1; i < cities.size(); i++) {
            for (int j = i; j > 0; j--) {
                if (cities[j].getCountOfPeople() < cities[j - 1].getCountOfPeople()) {
                    swap(cities[j], cities[j - 1]);
                }
                else break;
            }
        }
    }
    void showInfo(string name) {
        for (auto el : cities) {
            if (el.getName() == name) {
                cout << el;
                break;
            }
        }
    }

    void showAll() {
        for (auto el : cities) {
            cout << el;
        }
    }

};

int main()
{
    //vector<Animal*> animals;
    //animals.push_back(new Cow());
    //animals.push_back(new Cat());
    //animals.push_back(new Dog());
    //for (auto el : animals) {
    //    el->makeSound();
    //    cout << endl;
    //}

    //Ship ship;
    //ship.swim();
    //Car car;
    //car.drive();
    //Hydroplan hydroplan;
    //hydroplan.fly();
    //hydroplan.swim();
    //Money m1(23, 123);
    //Money m2(12, 90);
    //Money m3 = m1 + m2;
    ////m1.showMoney();
    //cout << m1 << endl;
    //cout << m2 << endl;
    //cout << m3 << endl;
    CityDatabase cities;
    cities.addCity(City("Tomsk", "Tomskaya", 400000));
    cities.addCity(City("Rostov", "Rostovskay", 1400000));
    cities.addCity(City("Surgut", "HMAO", 300000));
    cities.showAll();
    cout << "after sort" << endl;
    cities.sortByCountOfPeople();
    cities.showAll();
    try {
        cout << "find by name Surgut" << endl;
        City city = cities.findByName("Surgu");
        cout << city;
    }
    catch (const char* str) {
        cout << str;
    }
    


}
