#include <iostream>
using namespace std;

int main() {
	char a [] = "i";
	char b[] = "love";
	char c[] = "you";
	char* p[3];
	p[0] = a;
	p[1] = b;
	p[2] = c;
	cout << p[0] << p[1] << p[2] << endl;
	cout << *p[0] << *p[1] << *p[2] << endl;//
	for (int i = 0; i < 3; ++i) {
		cout << p[i] << " ";
	}
	cout << endl;
	return 0;
}