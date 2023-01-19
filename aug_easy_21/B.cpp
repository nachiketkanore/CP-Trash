/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 August 2021 11:52:10 PM IST
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
		string S;
		cin >> S;
		vector<int> digs;
		for (char ch : S) {
			digs.push_back(ch - '0');
		}
		int A = 0, B = 0;
		sort(ALL(digs), greater<int>());
		while (sz(digs) >= 2) {
			A = A * 10 + digs.back();
			digs.pop_back();
			B = B * 10 + digs.back();
			digs.pop_back();
		}
		if (sz(digs)) {
			A = A * 10 + digs.back();
			digs.pop_back();
		}
		cout << A + B << '\n';
	}
}
