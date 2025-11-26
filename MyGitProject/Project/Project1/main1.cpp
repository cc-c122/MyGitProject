#include <iostream>
using namespace std;

template <typename T>
class Queue{
private:
	T* date;
	int front;
	int rear;
	int capacity;
	void resize();
public:
	Queue() :date(new T[capacity]), front(0), rear(0), capacity(10) {};
	~Queue();
	void enqueue(T element);
	T getFront() const;
	T getSize() const;
};
template <typename T>
void Queue<T>::resize() {
	int newcapacity = capacity * 2;
	T* newdate = new T[newcapacity];
	for (int i = 0; i < rear; ++i) {
		newdate[i] = date[i];
	}
	delete[] date;
	date = newdate;
	capacity = newcapacity;
}

template <typename T>
Queue<T>::~Queue() {
	delete date;
}
template <typename T>
void Queue<T>::enqueue(T element){
	if (rear == capacity) {
		resize();
	}
	date[rear++] = element;
}//

template <typename T>
T Queue<T>::getFront() const{
	if (rear == front) {
		throw std::underflow_error("Queue is empty");
	}
	return date[front++];
}

template <typename T>
T Queue<T>::getSize() const{
	if (rear == front) {
		throw std::underflow_error("Queue is empty");
	}
	return date[front];
}

int main() {

	return 0;
}