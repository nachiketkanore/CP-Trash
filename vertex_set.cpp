/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 02:37:27 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 1e5, INF = 1e18;
int N, u, v, A[_], dp[_][2];
vector<int> g[_];

void go(int u, int par) {
	dp[u][0] = 0;
	dp[u][1] = A[u];
	for (int v : g[u]) {
		if (v ^ par) {
			go(v, u);
			dp[u][0] += max(dp[v][0], dp[v][1]);
			dp[u][1] += dp[v][0];
		}
	}
}

void dfs(int u, int par) {
	for (int v : g[u]) {
		if (v ^ par) {
			dfs(v, u);
			A[u] = max(A[u], A[v]);
		}
	}
}

void solve() {
	cin >> N;
	F0R(i, N) {
		g[i].clear();
		dp[i][0] = dp[i][1] = -INF;
	}
	F0R(i, N - 1) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	F0R(i, N) cin >> A[i];
	dfs(0, 0);
	go(0, 0);
	cout << max(dp[0][0], dp[0][1]) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}
