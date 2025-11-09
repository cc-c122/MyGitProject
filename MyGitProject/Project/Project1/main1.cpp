#include <iostream>
using namespace std;

int mm[10000][10000];

int main() {
	int n = 0, m = 0, max = 0, a = 0, b = 0;
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> mm[i][j];
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (mm[i][j] < 0) {
					mm[i][j] = ~mm[i][j] + 1;//
			    }
				if (max < mm[i][j]) {
					max = mm[i][j];
					a = i, b = j;
				}
			}
		}
		cout << a << ' ' << b << ' '<< max << endl;
	}
	return 0;
}