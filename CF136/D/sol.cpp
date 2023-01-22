/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 29 September 2022 08:33:20 PM IST
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

void solve() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> adj(N + 1);
	vector<int> cnt(N + 1);
	FOR(i, 2, N) {
		int par;
		cin >> par;
		adj[par].push_back(i);
	}

	function<void(int, int, int)> dfs = [&](int u, int p, int dep) {
		cnt[dep]++;
		for (int v : adj[u]) {
			if (p ^ v) {
				dfs(v, u, dep + 1);
			}
		}
	};
	dfs(1, 1, 0);
	int lo = 1, hi = N;
	int ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int best = 1e9;
		if (best <= K) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	assert(~ans);
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
