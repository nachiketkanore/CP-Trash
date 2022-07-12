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

int bits(int x) {
	int ret = 0;
	while (x) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

void solve() {
	int N, M;
	cin >> N >> M;
	vector<int> mask(N);
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		mask[u] |= 1 << v;
		mask[v] |= 1 << u;
	}
	F0R(i, N) {
		mask[i] |= 1 << i;
	}
	int ans = 0;
	F0R(comp, 1 << N) {
		int chk = (1 << N) - 1;
		int want = 0;
		F0R(i, N) if (comp >> i & 1) {
			chk &= mask[i];
			want |= 1 << i;
		}
		int cnt = bits(comp);
		if (chk == want) {
			ans = max(ans, cnt);
		}
	}
	cout << ans << '\n';
	// F0R(i, N) F0R(j, N) adj[i][j] = false;
	// F0R(i, M) {
	// 	int u, v;
	// 	cin >> u >> v;
	// 	--u, --v;
	// 	g[u].push_back(v);
	// 	g[v].push_back(u);
	// 	adj[u][v] = adj[v][u] = true;
	// }
	// int ans = 0;

	// for (int mask = (1 << N) - 1; mask >= 0; --mask) {
	// 	bool ok = true;
	// 	F0R(i, N) if (mask >> i & 1) {
	// 	}
	// 	// bool yes = true;
	// 	// for (int i = 0; i < sz(comp) && yes; i++) {
	// 	// 	for (int j = i + 1; j < sz(comp) && yes; j++) {
	// 	// 		yes &= adj[comp[i]][comp[j]];
	// 	// 	}
	// 	// }
	// 	// if (yes) {
	// 	// 	ans = max(ans, sz(comp));
	// 	// 	if (ans == N)
	// 	// 		break;
	// 	// }
	// }

	// cout << ans << '\n';
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
