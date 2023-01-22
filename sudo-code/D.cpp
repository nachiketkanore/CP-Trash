/**
 *    Author: Nachiket Kanore
 *    Created: Monday 08 November 2021 07:25:09 PM IST
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

int c2(int x, int r = 2) {
	if (x < 2)
		return 0;
	return x * (x - 1) / 2;
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int x, y;
		cin >> x >> y;
		assert(x > 0 && y > 0);
		assert(x <= 1e9 && y <= 1e9);
		int ans = c2(x, 2) * y + c2(y, 2) * x + x * y;
		cout << ans << '\n';
	}
}
