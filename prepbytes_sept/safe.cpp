/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 11 September 2021 03:01:33 PM IST
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

int digs(int n) {
	if (n == 0)
		return 0;
	return 1 + digs(n / 10);
}

bool diff_digs(int n) {
	int mask = 0;
	while (n > 0) {
		int d = n % 10;
		if (d == 0)
			return false;
		if (mask >> d & 1)
			return false;
		n /= 10;
		mask |= 1 << d;
	}
	return true;
}

bool divide(int n) {
	int val = n;
	bool ok = true;
	while (n) {
		int d = n % 10;
		if (d == 0)
			return false;
		ok &= val % d == 0;
		n /= 10;
	}
	return ok;
}

int32_t main() {
	int L, R, ans = 0;
	cin >> L >> R;
	FOR(i, L, R) {
		int val = i;
		bool ok = true;
		ok &= digs(val) == 6;
		ok &= diff_digs(val);
		ok &= divide(val);
		ans += ok;
	}
	cout << ans << '\n';
}
