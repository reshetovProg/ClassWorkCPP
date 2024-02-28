#pragma once
using namespace std;

class President {
private:
    string name;
    static President* instance;
    President(string name) {
        this->name = name;
    }
public:
    static President* getInstance(string name) {
        if (instance == nullptr) {
            instance = new President(name);
        }
        return instance;
    }
    void showInfo() {
        cout << this << " : " << name;
    }

};

President* President::instance = nullptr;