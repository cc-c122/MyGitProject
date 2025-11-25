#include <iostream>
#include <stdexcept>

using namespace std;

#define eleType int
struct Listnote {
	Listnote* next;
	eleType date;
	Listnote(eleType x) {
		date = x;
		next = NULL;
	}
};

class LinkedList {
private:
	Listnote* head;
	int size;

public:
	LinkedList() :head(NULL), size(0) {};
	~LinkedList();
	void insert(int i, eleType value);
	void remove(int i);
	Listnote* find(eleType value);
	Listnote* get(int i);
	Listnote* update(int i, eleType value);
	void print();
};

LinkedList::~LinkedList() {
	Listnote* curr = head;
	while (curr) {
		Listnote* tmp = curr;
		curr = curr->next;
		delete tmp;
	}
}
void LinkedList::insert(int i, eleType value) {
	if (i < 0 || i > size) {
		throw out_of_range("Incalid position");
	}
	Listnote* newNote = new Listnote(value);
	if (i == 0) {
		newNote->next = head;
		head = newNote;
	}
	else {
		Listnote* curr = head;
		for (int j = 0; j < i - 1; ++j) {
			curr = curr->next;
		}
		newNote->next = curr->next;
		curr->next = newNote;
	}
}
void LinkedList:: remove(int i) {
	if (i < 0 || i > size) {
		throw out_of_range("Incalid position");
	}
	if (i == 0) {
		Listnote* tmp = head;
		head = head->next;
		delete tmp;
	}
	else {
		Listnote* curr = head;
		for (int j = 0; j < i - 1; ++j) {
			curr = curr->next;
		}
		Listnote* tmp = curr->next;
		curr->next = tmp->next;
		delete tmp;
	}
}//

Listnote* LinkedList::find(eleType value) {
	Listnote* curr = head;
	while (curr && curr->date != value) {
		curr = curr->next;
	}
	return curr;
}

Listnote* LinkedList::get(int i) {
	if (i < 0 || i > size) {
		throw out_of_range("Incalid position");
	}
	Listnote* curr = head;
	for (int j = 0; j < i; ++j) {
		curr = curr->next;
	}
	return curr;
}
Listnote* LinkedList::update(int i, eleType value) {
	get(i)->date = value;
}

void LinkedList::print() {
	Listnote* curr = head;
	while(curr){
		cout << curr->date << ' ';
		curr = curr->next;
	}
	cout << endl;
}
int main() {

	return 0;
}