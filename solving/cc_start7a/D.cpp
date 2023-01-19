/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 July 2021 04:27:25 PM IST
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
		int A, B;
		cin >> A >> B;
		int mid = (A + B) / 2;
		int L = min(A, B), R = max(A, B);
		int ans = -1e18;
		FOR(X, mid - 50, mid + 50)
		if (L <= X && X <= R) {
			int val = ceil((B - X) / 2.) + ceil((X - A) / 2.);
			cmax(ans, val);
		}
		cout << ans << '\n';
	}
}
