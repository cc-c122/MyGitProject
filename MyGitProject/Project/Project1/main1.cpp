#include <iostream>
using namespace std;

int x[10000000];

int main() {
	int n, m, j, o, temp=0;
	while (cin >> n >> m) {
		o = 0, j = 0 ;
		if (n > m) {
			n = temp, temp = m, m = n;
		}
		for (int i = n; i <= m; ++i) {
			x[i] = i;//输入数组内容
			 if (x[i] % 2) {
				 j += x[i] * x[i] * x[i];
			 }
			 else {
				 o += x[i] * x[i];
			 }
		}
		cout << j << ' ' << o << endl;
	}
	return 0;
}