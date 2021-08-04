/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 02:40:43 PM IST
(ツ) Inspiration exists, but it has to find us working.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int r, n, t[N], x[N], y[N];
int maxDist;
int dp[N];

int getTime(int cx, int cy, int tx, int ty) {
	return abs(cx - tx) + abs(cy - ty);
}

int go(int id) {
	if (id > n)
		return 0;

	int &ans = dp[id];
	if (~ans)
		return ans;
	ans = 0;

	FOR (i, id + 1, min(id + maxDist + 20, n)) {
		int req = getTime(x[id], y[id], x[i], y[i]);
		int inTime = t[id] + req;

		if (inTime <= t[i]) {
			int get = 1 + go(i);
			ans = max(ans, get);
		}
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> r >> n;
	maxDist = r << 2;

	FOR (i,1,n) {
		cin >> t[i] >> x[i] >> y[i];
	}

	memset(dp, -1, sizeof(dp));
	int ans = 0;

	FOR (i,1,n) {
		if (getTime(1, 1, x[i], y[i]) <= t[i]) {
			int get = 1 + go(i);
			ans = max(ans, get);
		}
	}

	cout << ans << "\n";
}
