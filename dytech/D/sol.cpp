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
	const int INF = 1e17;
	vector<vector<int>> dist(N + 1, vector<int> (N + 1, INF));
	vector<set<int>> adj(N + 1);
	FOR (i,1,N) {
		dist[i][i] = 0;
	}
	auto add_edge = [&](int u, int v, int w) {
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = min(dist[v][u], w);
	};
	for (auto &[u, v, w]: edges) {
		cin >> u >> v >> w;
		add_edge(u, v, w);
		adj[u].insert(v);
		adj[v].insert(u);
	}
	set<array<int, 3>> Q;
	for (auto &[u, v, w]: edges) {
		for (int to: adj[u]) {
			add_edge(v, to, 2 * w);
			Q.insert({2 * w, v, to});
			adj[u].insert(to);
			adj[to].insert(u);
		}
		for (int to: adj[v]) {
			add_edge(u, to, 2 * w);
			Q.insert({2 * w, u, to});
			adj[v].insert(to);
			adj[to].insert(v);
		}
	}
	while (true) {
		auto [w, u, v] = *Q.begin();
		Q.erase(*Q.begin());
		if (w > INF) break;
		for (int to: adj[u]) {
			add_edge(v, to, 2 * w);
			Q.insert({2 * w, v, to});
			adj[v].insert(to);
			adj[to].insert(v);
		}
		for (int to: adj[v]) {
			add_edge(u, to, 2 * w);
			Q.insert({2 * w, u, to});
			adj[v].insert(to);
			adj[to].insert(u);
		}
	}
	FOR (k,1,N) FOR (a,1,N) FOR (b,1,N) dist[a][b] = min(dist[a][b], dist[a][k] + dist[k][b]);

	cout << dist[1][N] << '\n';
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
