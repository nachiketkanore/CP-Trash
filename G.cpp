/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 03 May 2022 06:37:25 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5;
const int INF = 1e9;
int N, M, dp[_], in[_], out[_];
vector<int> g[_];

int go(int u) {
	int& best = dp[u];
	if (~best)
		return best;
	best = 1;
	if (out[u] >= 2 && in[u] >= 2) {
		for (int v : g[u]) {
			if (in[v] >= 2)
				best = max(best, 1 + go(v));
		}
	}
	return best;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		in[v]++, out[u]++;
	}
	int ans = 1;
	FOR(i, 1, N) {
		if (out[i] >= 2) {
			for (int nxt : g[i]) {
				ans = max(ans, 1 + go(nxt));
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
