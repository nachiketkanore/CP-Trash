/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 09:45:33 AM IST
(ツ) We can change our lives. We can do, have, and be exactly what we wish.
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

const int inf = 1e18;
int dp[10][10005];
int n, m;

int go(int from, int mod) {
	if (from > n)
		return inf;
	if (from == n)
		return (mod == 0 ? 0 : inf);

	if (mod == -1)
		mod = 0;
	int& ans = dp[mod][from];
	if (~ans)
		return ans;
	ans = inf;

	int c1 = 1 + go(from + 1, (mod + 1) % m);
	int c2 = 1 + go(from + 2, (mod + 1) % m);
	ans = min(c1, c2);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	int ans = go(0, 0);
	if (ans >= inf)
		cout << -1;
	else
		cout << ans;
}
