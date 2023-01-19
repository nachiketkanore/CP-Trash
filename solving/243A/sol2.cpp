#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	function<void(int, int, int)> f = [&](int a, int b, int c) { cout << a << ' ' << b << ' ' << c << '\n'; };
	f(1, 2, 3);
}