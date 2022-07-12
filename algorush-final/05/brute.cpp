/**
 *    Author: Nachiket Kanore
 *    Created: Friday 08 July 2022 11:45:23 AM IST
 **/

#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int_fast32_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

bool adj[21][21];

void solve() {
	int N, M;
	cin >> N >> M;
	F0R(i, N) F0R(j, N) adj[i][j] = false;
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u][v] = adj[v][u] = true;
	}
	int ans = 0;

	for (int mask = (1 << N) - 1; mask >= 0; --mask) {
		vector<int> comp;
		F0R(i, N) if (mask >> i & 1) {
			comp.push_back(i);
		}
		bool yes = true;
		for (int i = 0; i < sz(comp) && yes; i++) {
			for (int j = i + 1; j < sz(comp) && yes; j++) {
				yes &= adj[comp[i]][comp[j]];
			}
		}
		if (yes) {
			ans = max(ans, sz(comp));
			if (ans == N)
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

	while (T--) {
		solve();
	}

	return 0;
}
