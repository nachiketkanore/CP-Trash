/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 02:05:28 PM IST
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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool odd = false, even = false;
		FOR(i, 1, n) {
			int u;
			cin >> u;
			odd |= u % 2 == 1;
			even |= u % 2 == 0;
		}
		if (n > 1) {
			cout << (odd ? "YES\n" : "NO\n");
		} else {
			cout << (even ? "YES\n" : "NO\n");
		}
	}
}
