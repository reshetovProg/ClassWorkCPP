#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


// ---- декоратор ----
//class Writing {
//public:
//    virtual void write(string path, string str)=0;
//};
//
//class FileManager : public Writing {
//public:
//    void write(string path, string str) {
//        ofstream out(path);
//        out << str;
//        out.close();
//    }
//};
//
//class FileDecorator : public Writing {
//protected:
//    Writing* wrapper;
//public:
//    FileDecorator(Writing* wrapper) {
//        this->wrapper = wrapper;
//    }
//    virtual void write(string path, string str) = 0;
//};
//
//class EncrypterFileDecorator : public FileDecorator {
//public:
//    EncrypterFileDecorator(Writing* wrapper): 
//        FileDecorator(wrapper) {            
//    }
//    void write(string path, string str) {
//        for (int i = 0; i < str.size(); i++) {
//            str[i] += 1;
//        }
//        wrapper->write(path, str);
//    }
//};

//компоновщик
//class Branch {
//private:
//    int count;
//public:
//    Branch(int count) {
//        this->count = count;
//    }
//    int getCount()
//    { 
//        return count;
//    }
//};
//
//class Filial {
//private:
//    vector<Branch> branches;
//public:
//    void addBranche(Branch branch) {
//        branches.push_back(branch);
//    }
//    int getCount()
//    {
//        int summ = 0;
//        for (auto el : branches) {
//            summ+=el.getCount();
//        }
//        return summ;
//    }
//};
//
//class Company {
//private:
//    vector<Filial> filials;
//public:
//    void addBranche(Filial filial) {
//        filials.push_back(filial);
//    }
//    int getCount()
//    {
//        int summ = 0;
//        for (auto el : filials) {
//            summ += el.getCount();
//        }
//        return summ;
//    }
//};

// адаптер
//class Car {
//private:
//    int width;
//    int height;
//    int length;
//public:
//    Car(int width,
//        int height,
//        int length) {
//        this->width = width;
//        this->height = height;
//        this->length = length;
//    }
//    int getWidth() { return width; }
//    int getHeight() { return height; }
//    int getLength() { return length; }
//};
//
//class Box {
//private:
//    float V;
//public:
//    Box() {}
//    Box(float V) {
//        this->V = V;
//    }
//    float getV() { return V; }
//};
//
//class CarAdapterBox: public Box {
//private:
//    float V;
//public:
//    CarAdapterBox(Car car) {
//        this->V = car.getHeight()*car.getLength()*car.getWidth();
//    }
//};
//
//class Fura {
//private:
//    float V;
//public:
//    Fura(float V) {
//        this->V = V;
//    }
//    bool packageBagage(Box box) {
//        return box.getV() <= V;
//    }
//};

//мост

class Device {
public:
    virtual void upVolume() = 0;
    virtual void downVolume() = 0;
    virtual void upChannel() = 0;
    virtual void downChannel() = 0;
};

class Tv : public Device {
public:
    void upVolume() {
        cout << "tv up volume"<<endl;
    }
    void downVolume() {
        cout << "tv down volume" << endl;
    }
    void upChannel() {
        cout << "tv up channel" << endl;
    }
    void downChannel() {
        cout << "tv down channel" << endl;
    }
};

class Radio : public Device {
public:
    void upVolume() {
        cout << "radio up volume" << endl;
    }
    void downVolume() {
        cout << "radio down volume" << endl;
    }
    void upChannel() {
        cout << "radio up channel" << endl;
    }
    void downChannel() {
        cout << "radio down channel" << endl;
    }
};

class Remote {
    Device* device;
public:
    Remote(Device* device) {
        this->device = device;
    }
    void upVolume() {
        device->upVolume();
    }
    void downVolume() {
        device->downVolume();
    }
    void upChannel() {
        device->upChannel();
    }
    void downChannel() {
        device->downChannel();
    }

};


int main()
{
    // --- декоратор ---
    //Writing* writer = new FileManager;
    //writer->write("text.txt", "qwerty");

    //writer = new EncrypterFileDecorator(writer);
    //writer->write("text1.txt", "qwerty");

    //компоновщик
   /* Company company;
    Filial f1, f2;
    f1.addBranche(Branch(10));
    f1.addBranche(Branch(5));
    f2.addBranche(Branch(5));
    company.addBranche(f1);
    company.addBranche(f2);
    cout << company.getCount();*/

    // адаптер
    //Box box1(20);
    //Fura fura(20);
    //cout<<fura.packageBagage(box1);
    //Car car1(2,5,2);
    //CarAdapterBox adapter(car1);
    //cout << fura.packageBagage(adapter);


    Remote remote1(new Radio);
    Remote remote2(new Tv);

    remote1.downChannel();
    remote1.upChannel();
    remote1.downVolume();
    remote1.upVolume();

    remote2.downChannel();
    remote2.upChannel();
    remote2.downVolume();
    remote2.upVolume();
}
