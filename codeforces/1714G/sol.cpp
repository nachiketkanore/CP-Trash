/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 12:32:36 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 2e5 + 5;
int N, ans[_];
vector<array<int, 3>> adj[_];

void dfs(int u, vector<array<int, 3>>& info, int asum, int bsum, int pathlen) {
	info.push_back({ bsum, pathlen, sz(info) ? max(pathlen, info.back()[2]) : pathlen });
	int id = -1;
	int lo = 0, hi = sz(info) - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (info[mid][0] <= asum) {
			id = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	assert(~id);
	ans[u] = info[id][2];
	/* for (auto [bval, len, _] : info) {
		if (bval <= asum)
			ans[u] = max(ans[u], len);
	} */
	for (auto [v, a, b] : adj[u]) {
		dfs(v, info, asum + a, bsum + b, pathlen + 1);
	}
	info.pop_back();
}

void solve() {
	cin >> N;
	FOR(i, 1, N) adj[i].clear(), ans[i] = 0;
	FOR(u, 2, N) {
		int v, a, b;
		cin >> v >> a >> b;
		adj[v].push_back({ u, a, b });
	}
	vector<array<int, 3>> info;
	dfs(1, info, 0, 0, 0);
	FOR(i, 2, N) cout << ans[i] << " \n"[i == N];
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
