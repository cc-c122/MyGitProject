# include <iostream>
using namespace std;

void so(int &a, int &b, int &c);

int main() {
	int t = 0;
	cin >> t;
	while (t--) {
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		so(a, b, c);
		if (b + c > a) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;//
}

void so(int &a, int &b, int &c) {
	int tmp = 0;
	if (a < b) {
		tmp = a, a = b , b = tmp;
	}
	if (a < c) {
		tmp = a, a = c, c = tmp;
	}
	if (b < c) {
		tmp = b, b = c, c = tmp;
	}
}