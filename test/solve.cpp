#include <bits/stdc++.h>
using namespace std;

void test() {
	int hello;
	cin >> hello;
	while (hello-- > 0) {
		cout << "HELLO WORLD\n";
	}
}

void solve() {
	int N, sum = 0;
	cin >> N;
	vector<int> A(N);
	for (int& x : A) {
		cin >> x;
		sum += x;
	}
}

int main() {
	test();
	return 0;
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}