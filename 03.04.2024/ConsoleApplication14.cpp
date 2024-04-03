#include <iostream>
using namespace std;

//паттерн стратегия
//class Instrument {
//public:
//    virtual void draw()=0;
//};
//
//class Brush :public Instrument {
//public:
//    void draw() {
//        cout << "brush draw" << endl;
//    }
//};
//
//class Pencil :public Instrument {
//public:
//    void draw() {
//        cout << "pencil draw" << endl;
//    }
//};
//
//class Marker :public Instrument {
//public:
//    void draw() {
//        cout << "marker draw" << endl;
//    }
//};
//
//class Field {
//    Instrument* instr;
//public:
//    void setInstrument(Instrument* instr) {
//        this->instr = instr;
//    }
//    void draw() {
//        instr->draw();
//    }
//};


//состояние
class Teapot {
    State* state;
public:
    void changeState(State* state) {
        this->state = state;
    }
    void on() {
        state->on();
    }
    void off() {
        state->off();
    }
    void onTermo() {
        state->onTermo();
    }

};

class State {
protected:
    Teapot* teapot;
public:
    State(Teapot* teapot) {
        this->teapot = teapot;
    }
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void onTermo() = 0;
};

class On : public State {
public:
    On(Teapot* teapot):State(teapot) {}
    void on() {
    }
    void off() {
        cout << "чайник выключен" << endl;
        teapot->changeState(new Off(teapot));
    }
    void onTermo() {

    }
};

class Off : public State {
public:
    Off(Teapot* teapot) :State(teapot) {}
    void on() {
        cout << "чайник включен" << endl;
        teapot->changeState(new On(teapot));
    }
    void off() {
    }
    void onTermo() {
        cout << "включени режим термо" << endl;
        teapot->changeState(new OnTermo(teapot));
    }
};

class OnTermo : public State {
public:
    OnTermo(Teapot* teapot) :State(teapot) {}
    void on() {
    }
    void off() {
        cout << "чайник выключен" << endl;
        teapot->changeState(new Off(teapot));
    }
    void onTermo() {
    }
};

int main()
{
   /* Field field;
    field.setInstrument(new Brush);
    field.draw();
    field.draw();
    field.setInstrument(new Pencil);
    field.draw();*/


}
