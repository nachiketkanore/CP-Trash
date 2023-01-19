/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 July 2021 09:29:27 PM IST
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

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int32_t main() {
	const int inf = 1e18;
	const int MOD = 1e9 + 7;
	int N, C;
	cin >> N >> C;
	assert(N < 1000000);
	vector<int> h(N), dp(N, inf);
	dp[0] = 0;
	for (int& x : h)
		cin >> x;
	F0R(i, N) {
		int T = 50;
		for (int j = i - 1; j >= 0 && T--; j--) {
			cmin(dp[i], dp[j] + (h[i] - h[j]) * (h[i] - h[j]) + C);
		}
	}
	dp[N - 1] %= MOD;
	cout << dp[N - 1];
}
