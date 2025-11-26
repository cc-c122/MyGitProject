#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
	T* date;
	int size;
	int capacity;
	void resize();
public:
	Stack() : date(new T[10]), size(0), capacity(10);
	~Stack();
	void push(T element);
	T pop();
	T top() const;
	int getSize() const;
};
template <typename T>
void Stack<T>::resize() {
	int newcapacity = capacity * 2;
	T* newdate = new T[newcapacity];
	for (int i = 0; i < capacity; i++) {
		newdate[i] = date[i];
	}
	delete[] date;
	capacity = newcapacity;
	date = newdate;
}

template <typename T>
Stack<T>::~Stack() {
	delete[]date;
}

template <typename T>
void Stack<T>::push(T element) {
	if (size == capacity) {
		resize();
	}
	date[size++] = element;
}

template <typename T>
T Stack<T>::pop() {
	if (size == 0) {
		throw std::underflow_error("Stack is empty");
	}
	return date[--size];
}

template <typename T>
T Stack<T>::top() const {
	if (size == 0) {
		throw std::underflow_error("Stack is empty");
	}
	return date[size - 1];
}

template <typename T>
int Stack<T>::getSize() const {
	return size;
}/

int main() {

	return 0;
}