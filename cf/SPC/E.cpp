/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 12:54:20 PM IST
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
		// can we make 'u' mod k == 0
		// (u + x.d) mod k = 0
		// u + x.d = quo.k
		// u = quo.k - x.d
		// u = G.(quo.(G/k) - x.(G/k))
		// where G = gcd(k, d)
		// => u % G should be 0
		int n, d, k;
		cin >> n >> d >> k;
		bool poss = true;
		FOR(i, 1, n) {
			int u;
			cin >> u;
			poss &= u % __gcd(d, k) == 0;
		}
		cout << (poss ? "YES\n" : "NO\n");
	}
}
