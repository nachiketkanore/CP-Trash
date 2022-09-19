/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 September 2022 10:27:31 PM IST
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
	int N, Q; cin >> N >> Q;
	vector<vector<int>> adj(N + 1);
	FOR (i, 2, N) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	FOR (i, 1, Q) {
		int u; cin >> u;
		// useless
	}
	vector<int> depth_count(N + 1);
	function<void(int, int, int)> dfs = [&](int u, int par, int dep) {
		depth_count[dep]++;
		for (int v: adj[u]) {
			if (v ^ par) {
				dfs(v, u, dep + 1);
			}
		}
	};
	dfs(1, 1, 1);
	int have = Q, ans = 0;
	FOR (depth, 1, N) {
		if (depth_count[depth] == 0) break;
		if (have >= depth_count[depth]) {
			ans += depth_count[depth];
			have -= depth_count[depth];
		} else {
			break;
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR (tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
