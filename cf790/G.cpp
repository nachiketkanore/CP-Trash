/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 10 May 2022 08:01:20 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 5e5 + 5;
vector<int> g[_];
int col[_], sub[_];

void dfs(int u = 1, int par = 1) {
	sub[u] = col[u];
	for (int v : g[u]) {
		if (v ^ par) {
			dfs(v, u);
			sub[u] += sub[v];
		}
	}
}

void solve() {
	int N;
	cin >> N;
	FOR(i, 1, N) {
		g[i].clear();
		col[i] = sub[i] = 0;
	}
	FOR(i, 2, N) {
		int par;
		cin >> par;
		g[par].push_back(i);
	}
	FOR(i, 1, N) {
		char ch;
		cin >> ch;
		col[i] = ch == 'W' ? 1 : -1;
	}
	dfs();
	int ans = 0;
	FOR(i, 1, N) {
		ans += sub[i] == 0;
	}
	cout << ans << '\n';
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
