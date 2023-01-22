/**
 *    Author: Nachiket Kanore
 *    Created: Friday 06 August 2021 04:38:13 PM IST
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
		int one = 0, two = 0;
		FOR(i, 1, 3) {
			int u;
			cin >> u;
			one += u;
		}
		FOR(i, 1, 3) {
			int u;
			cin >> u;
			two += u;
		}
		if (one > two)
			cout << "1\n";
		else if (two > one)
			cout << "2\n";
		else
			assert(false);
	}
}
