/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 03:48:17 PM IST
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

const int N = 2e5 + 5;
int dp[N];

bool go(int rem) {
	if (~dp[rem])
		return dp[rem];
	bool win = false;
	for (int take = 1; take * take <= rem; take++) {
		win |= go(rem - take * take) == 0;
	}
	dp[rem] = win;
	return win;
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (go(n))
			cout << "Amarnath\n";
		else
			cout << "Tej\n";
	}
}
