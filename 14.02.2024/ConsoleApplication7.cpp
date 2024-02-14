
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
};

template <typename T>
class LinkedList {
    Node<T>* head = nullptr;
    int count = 0;
public:
    void push(T value) {
        Node<T>* newNode =new Node<T>{ value, head };
        head = newNode;
        count++;
    }

    void showAll() {
        Node<T>* buf = head;
        while (buf->next != nullptr) {
            cout << buf->value << " ";
            buf = buf->next;
        }
        cout << buf->value;
        cout << endl;
    }

    void insert(T value, int index) {
        if (index >= count || index < 0) return;
        if (index == 0) {
            push(value);
            return;
        }
        Node<T>* buf = head;
        for (int i = 0; i < index-1; i++) {
            buf = buf->next;
        }
        Node<T>* newNode = new Node<T>{ value, buf->next };
        buf->next = newNode;
        count++;
    }

    void dropHead() {
        if (count == 0) return;
        Node<T>* buf = head;
        head = head->next;
        count--;
        delete[] buf;
    }

};


int main()
{
    LinkedList<int> list;
    for (int i = 0; i < 10; i++) {
        list.push(i);
    }
    list.showAll();
    list.insert(100, 0);
    list.showAll();
    list.dropHead();
    list.showAll();

}

