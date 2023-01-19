/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 02:26:17 PM IST
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
		int N, K;
		cin >> N >> K;
		auto bad = [&](int u) {
			int mask = 0;
			while (u)
				mask |= 1 << (u % 10), u /= 10;
			return __builtin_popcount(mask) > K;
		};
		while (bad(N))
			++N;
		cout << N << '\n';
	}
}
