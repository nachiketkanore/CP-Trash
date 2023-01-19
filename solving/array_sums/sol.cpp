/*
Author: Nachiket Kanore
Created: Monday 14 December 2020 12:13:32 PM IST
(ツ) The best and most beautiful things in the world cannot be seen, nor touched... but are felt in the heart.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 10002, inf = 1e18;

int n, a[N], b[N];
bool poss[1002];
bool dp[N][1002];
bool vis[N][1002];

int go(int id, int rem) {
	if (rem < 0)
		return 0;
	if (id < 0)
		return rem == 0;
	if (vis[id][rem])
		return dp[id][rem];
	vis[id][rem] = true;
	int ans = 0;
	ans |= go(id - 1, rem);
	ans |= go(id - 1, rem - a[id]);
	dp[id][rem] = ans;
	return ans;
}

void solve() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		b[i] = a[i];
		poss[a[i]] = false;
	}
	sort(a + 1, a + n + 1);
	FOR(i, 1, n) FOR(j, 0, a[n]) vis[i][j] = false;

	FOR(i, 1, n) {
		int get = go(i - 1, a[i]);
		if (get)
			poss[a[i]] = true;
	}

	FOR(i, 1, n) cout << (poss[b[i]] ? 1 : 0) << " \n"[i == n];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
