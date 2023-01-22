/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 02:15:44 PM IST
(ツ) Life is a succession of moments. To live each one is to succeed.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 1, mod = 210;

int n;
int dp[mod][N];

int go(int id, int modulo) {
	if (id == n + 1)
		return modulo == 0;
	int& ans = dp[modulo][id];
	if (~ans)
		return ans;
	ans = 0;
	FOR(d, 0, 9) ans |= go(id + 1, (modulo * 10 + d) % mod);
	return ans;
}

void trace(int id, int modulo) {
	if (id == n + 1) {
		assert(!modulo);
		return;
	}
	int ans = go(id, modulo);
	assert(ans);

	FOR(d, 0, 9) {
		int get = go(id + 1, (modulo * 10 + d) % mod);
		if (get) {
			cout << d;
			return trace(id + 1, (modulo * 10 + d) % mod);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));

	FOR(d, 1, 9) if (go(2, d % mod)) {
		cout << d;
		trace(2, d % mod);
		cout << "\n";
		return 0;
	}
	cout << "-1\n";
}
