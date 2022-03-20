/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 20 March 2022 05:51:54 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int MOD = 998244353;
int N, M, K, S, T, X;
const int _ = 2005;
vector<int> g[_];
int dp[2][_][_];

int go(int id, int prev, int mod) {
	if (id == K + 1) {
		return prev == T && mod % 2 == 0;
	}
	int &ans = dp[mod % 2][id][prev];
	if (~ans) return ans;
	ans = 0;
	for (int nxt: g[prev]) {
		ans += go(id + 1, nxt, mod + (nxt == X));
		if (ans >= MOD)
			ans -= MOD;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K >> S >> T >> X;
	for (int i = 0, u, v; i < M; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int ans = go(1, S, 0);
	cout << ans << '\n';
	return 0;
}
