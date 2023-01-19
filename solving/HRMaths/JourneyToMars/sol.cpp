/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 24 April 2021 01:12:20 AM IST
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
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 5e5 + 5;

int power(int a, int b, int mod) {
	int ret = 1;
	a %= mod;
	while (b > 0) {
		if (b % 2)
			ret = ret * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return ret;
}

int get_first(long double a, long double b, int n) {
	long double x, y;
	x = b * log10(a);
	y = floor(pow(10, x - floor(x) + n - 1));
	return int(y);
}

int get_last(int a, int b, int k) {
	int pow10 = 1;
	while (k--)
		pow10 *= 10;
	return power(a, b, pow10);
}

void solve() {
	int n, k;
	cin >> n >> k;
	using ld = long double;
	int fi = get_first((ld)2, ld(n - 1), k);
	int ls = get_last(2, n - 1, k);
	cout << fi + ls << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
}
