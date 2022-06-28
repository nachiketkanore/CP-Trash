/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 June 2022 12:15:49 AM IST
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

const int _ = 1e5;
int u[_], v[_];
vector<pair<int, int>> g[_];
bool nactive[55][_], eactive[55][_], vis[55][_];

void solve() {
	memset(nactive, false, sizeof(nactive));
	memset(vis, false, sizeof(vis));
	memset(eactive, false, sizeof(eactive));
	int N;
	cin >> N;
	FOR(i, 1, N) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int L, R;
			cin >> L >> R;
			FOR(tim, L, R) {
				nactive[tim][i] = true;
			}
		}
	}
	int M;
	cin >> M;
	FOR(i, 1, M) {
		cin >> u[i] >> v[i];
		g[u[i]].push_back({ v[i], i });
		g[v[i]].push_back({ u[i], i });
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int L, R;
			cin >> L >> R;
			FOR(tim, L, R) {
				eactive[tim][i] = true;
			}
		}
	}

	int X, D;
	cin >> X >> D;
	queue<pair<int, int>> Q;
	FOR(tim, 0, 50) {
		if (nactive[tim][X]) {
			Q.push({ tim, X });
		}
	}

	while (!Q.empty()) {
		auto [curr, u] = Q.front();
		Q.pop();

		if (vis[curr][u])
			continue;

		vis[curr][u] = true;

		for (auto [v, id] : g[u]) {
			if (nactive[curr][v] && eactive[curr][id]) {
				Q.push({ curr, v });
			}
		}
	}

	int ans = 0;
	F0R(i, 55) ans += vis[i][D];
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
