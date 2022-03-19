/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 March 2022 03:44:44 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	cin >> N >> M;
	int dist[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 1e18;
			if (i == j) dist[i][j] = 0;
		}
	}
	vector<array<int,3>> edges;
	for (int i = 0, u, v, c; i < M; i++) {
		cin >> u >> v >> c;
		--u, --v;
		dist[u][v] = c;
		dist[v][u] = c;
		edges.push_back({u, v, c});
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for (auto [u, v, c]: edges) {
		bool better = false;
		for (int i = 0; i < N; i++) {
			if (i == u || i == v) continue;
			if (dist[u][i] + dist[i][v] <= c) {
				better = true;
				break;
			}
		}
		if (better) ++ans;
	}
	cout << ans << '\n';
	return 0;
}
