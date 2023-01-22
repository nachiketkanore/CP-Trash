/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 August 2021 07:58:59 PM IST
 **/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
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
	const int INF = 1e6;
	int N;
	cin >> N;
	int ans = INF;

	function<int(int, int)> go = [&](int a, int b) {
		if (b == 0)
			return INF;
		if (b == 1)
			return a - 1;
		return a / b + go(b, a % b);
	};

	FOR(i, 1, N) cmin(ans, go(i, N));
	cout << ans << '\n';
}
