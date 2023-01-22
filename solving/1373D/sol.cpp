/*
Author: Nachiket Kanore
Created: Monday 16 November 2020 03:24:54 PM IST
(ツ) The day you decide to do it is your lucky day.
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

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, a[N], dp[3][N];

int go(int id, int state) {
	if (id == n)
		return 0;
	int& ans = dp[state][id];
	if (~ans)
		return ans;
	ans = 0;

	if (state == 0) { // start reversing subarray from here
		// start here
		int c1 = 0;
		if (id + 1 < n) {
			c1 = go(id + 2, 1);
			if (id % 2)
				c1 += a[id];
			else
				c1 += a[id + 1];
		}
		// start next
		int c2 = go(id + 1, 0);
		if (id % 2 == 0)
			c2 += a[id];
		ans = max({ ans, c1, c2 });
	} else if (state == 1) { // already started reversing subarray before
		// stop that
		int c1 = go(id + 1, 2);
		if (id % 2 == 0)
			c1 += a[id];
		ans = max(ans, c1);

		// continue
		c1 = 0;
		if (id + 1 < n) {
			c1 = go(id + 2, 1);
			if (id % 2)
				c1 += a[id];
			else
				c1 += a[id + 1];
		}
		ans = max(ans, c1);

	} else if (state == 2) { // finished reversing one subarray
		int c1 = go(id + 1, 2);
		if (id % 2 == 0)
			c1 += a[id];
		ans = max(ans, c1);
	} else
		assert(false);

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		FOR(i, 1, n) {
			cin >> a[i - 1];
			if (i & 1)
				ans += a[i - 1];
			dp[0][i - 1] = dp[1][i - 1] = dp[2][i - 1] = -1;
		}
		ans = max(ans, go(0, 0));
		cout << ans << "\n";
	}
}
