#include <iostream>
using namespace std;

int n[100];
int sushu(int);

int main() {
	int x = 0, y = 0;
	while (cin >> x >> y) {
		if (x == 0 && y == 0) {
			break;
		}
		int num = 0;
		for (int i = x; i <= y; ++i) {
			n[i] = i * i + i + 41;
		}
		for (int i = x; i <= y; ++i) {
			num += sushu(n[i]);
		}
		if (y - x + 1 == num) {
			cout << "OK" << endl;//
		}
		else {
			cout << "SORRY" << endl;
		}
	}
	return 0;
}

int  sushu(int x) {
	if (x < 2) {
		return 0;
	}
	else if (x == 2) {
		return 1;
	}
	else {
		for (int i = 2; i * i <= x; ++i) {
			if (x % i == 0) {
				return 0;
			}	
		}
		return 1;
	}
}