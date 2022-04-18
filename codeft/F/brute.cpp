/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 10:21:11 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _	  = 105;
const int MOD = 1e9 + 7;
set<int> g[_];
int N, M, K, H;
int dp[1000][1000];

int go(int u, int rem) {
	if (rem == 0)
		return u == H;
	int& ans = dp[u][rem];
	if (~ans)
		return ans;
	ans = 0;
	for (int v : g[u]) {
		ans += go(v, rem - 1);
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M >> K >> H;
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}
	cout << go(H, K) << '\n';
	return 0;
}
