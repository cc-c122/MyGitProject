#include <iostream>
using namespace std;

#define eleType int

struct Sequentialist {
	eleType* elements;
    int size;
	int capacity;
};

void initializeList(Sequentialist* list, int capacity) {
	list->elements = new eleType[capacity];
	list->capacity = capacity;
	list->size = 0;
}

void destroyList(Sequentialist* list) {
	delete[] list->elements;
}

int size(Sequentialist* list) {
	return list->size;
}

bool isEmpty(Sequentialist* list) {
	if (list->size == 0) {
		return -1;
	}
	else {
		return 1;
	}
}

void insert(Sequentialist* list, int index, eleType count) {
	if (index < 0 || index > list->size) {
		throw std::invalid_argument("Invalid index");
	}
	if (list->size == list->capacity) {
		int Newcapacity = list->capacity * 2;
		eleType* Newelements = new eleType[Newcapacity];
		for (int i = 0; i < list->size; i++) {
			Newelements[i] = list->elements[i];
		}
		delete list->elements;
		list->elements = Newelements;
		list->capacity = Newcapacity;
	}
	for (int i = list->size; i > index; --i) {
		list->elements[i] = list->elements[i-1];
	}
	list->elements[index] = count;
	list->size++;
}

void deleteElement(Sequentialist* list, int index) {
	if (index < 0 || index >= list->size) {
		throw std::invalid_argument("Invalid index");
	}
	for (int i = index; i < list->size; ++i) {
		list->elements[i] = list->elements[i + 1];
	}
	list->elements--;
}

int findElements(Sequentialist* list, eleType element) {
	for (int i = 0; i < list->size; ++i) {
		if (list->elements[i] == element) {
			return i;
		}
	}//
	return -1;
}

eleType getElements(Sequentialist* list, int index) {
	if (index < 0 || index >= list->size) {
		throw std::invalid_argument("Invalid index");
	}
	return list->elements[index];
}

void updateElements(Sequentialist* list, int index, eleType count) {
	if (index < 0 || index >= list->size) {
		throw std::invalid_argument("Invalid index");
	}
	list->elements[index] = count;
}