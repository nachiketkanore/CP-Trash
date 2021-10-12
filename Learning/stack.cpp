#include <iostream>
using namespace std;

int get_sum(int* a, int l, int r) {
	return a[r] - (l ? a[l-1]: 0);
}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i > 0) {
				a[i] += a[i-1];
			}
		}
		cout << get_sum(a, 0, n-1);
	}
}
