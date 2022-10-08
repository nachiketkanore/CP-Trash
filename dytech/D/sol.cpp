/**
 *    Author: Nachiket Kanore
 *    Created: Friday 07 October 2022 10:19:41 PM IST
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
	int N, M;
	cin >> N >> M;
	vector<array<int, 3>> edges(M);
	const int INF = 1e14;
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
	FOR(i, 1, N) {
		dist[i][i] = 0;
	}
	for (auto& [u, v, w] : edges) {
		cin >> u >> v >> w;
		dist[u][v] = 1;
		dist[v][u] = 1;
	}
	FOR(k, 1, N) FOR(u, 1, N) FOR(v, 1, N) dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
	int ans = INF;
	F0R(rep, 2) {
		for (auto& [u, v, w] : edges) {
			swap(u, v);
			int c1 = w * (dist[1][u] + dist[v][N] + 1);
			ans = min(ans, c1);
			FOR(loop, 1, N) {
				int c2 = w * (dist[1][loop] + dist[loop][N] + dist[u][loop] + 2);
				ans = min(ans, c2);
			}
		}
	}
	assert(ans ^ INF);
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
