/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 18 August 2021 03:25:04 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
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
		int A, B, C;
		cin >> A >> B >> C;
		int X;
		cin >> X;
		int R, P, T;
		cin >> R >> P >> T;
		const int INF = 1e9;
		auto check = [&](int q, int who) {
			if (who == R && q == P)
				return true;
			return false;
		};
		function<int(int, int, int, int)> go = [&](int rem, int a, int b, int c) {
			if (rem < 0)
				return INF;
			if (check(a, 0))
				return int(0);
			if (check(b, 0))
				return int(0);
			if (check(c, 0))
				return int(0);
			int ans = INF;

			return ans;
		};
		int ans = go(T, X == 0 ? A : 0, X == 1 ? B : 0, X == 2 ? C : 0);
		if (ans >= INF)
			ans = -1;
		cout << ans << '\n';
	}
}
