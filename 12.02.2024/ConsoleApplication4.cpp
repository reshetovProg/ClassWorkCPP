#include <iostream>

using namespace std;

template <typename T>
class Stack {
	T* stack = nullptr;
	int count=0;
	int capacity;
public:
	Stack(int capacity)  
	{
		stack = new T[capacity];
		this->capacity = capacity;
	}

	Stack (Stack& st) {
		this->count = st.count;
		this->capacity = st.capacity;
		if (stack != nullptr) delete[]stack;
		stack = new T[capacity];
		for (int i = 0; i < count; i++) {
			stack[i] = st.stack[i];
		}
	}

	void operator = (Stack& st) {
		this->count = st.count;
		this->capacity = st.capacity;
		if (stack != nullptr) delete[]stack;
		stack = new T[capacity];
		for (int i = 0; i < count; i++) {
			stack[i] = st.stack[i];
		}
	}
	~Stack() {
		if (stack!=nullptr)
			delete[]stack;
	}
	T top() {
		return stack[count - 1];
	}

	bool empty() {
		return !count;
	}

	int size() {
		return this->count;
	}
	void push(T el) {
		if (count >= capacity) return;
		stack[count++] = el;
	}
	T pop() {
		if (count == 0) return NULL;
		count--;
		return stack[count];
	}

};


template <typename T>
void showStack(Stack<T> stack) {
	while (!stack.empty()) {
		cout << stack.pop();
	}
}



int main()
{
	Stack<int> stack(3);
	cout << "---push 3 4 6 9 ---" << endl;
	stack.push(3);
	stack.push(4);
	stack.push(6);
	stack.push(9);
	cout << "--- pop" << endl;
	cout<<stack.pop() <<endl;
	cout << "--- showAll----" << endl;
	showStack(stack);
	cout << stack.top();


	

	

}
