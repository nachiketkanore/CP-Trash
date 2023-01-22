/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 October 2021 04:22:26 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

void solve() {
	int X, K;
	cin >> X >> K;
	int L = X, R = X * K;
	cout << lcm(L, 2 * L) << ' ' << lcm(R - 1, R) << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
