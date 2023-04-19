#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, vector<pair<int, int>>> g;
#define inf 1e18
int node[100010], dist[100010];
set<pair<int, int>> s;
int n, m;

void printPath(int n) {
	if (n != 1)
		printPath(node[n]);
	cout << n << " ";
}

int32_t main() {
	cin >> n >> m;
	int u, v, w;
	while (m--) {
		cin >> u >> v >> w;
		g[u].push_back({ v, w }), g[v].push_back({ u, w });
	}

	s.insert({ 0, 1 });

	for (int i = 1; i <= n; i++)
		dist[i] = inf, node[i] = i;

	dist[1] = 0;

	while (!s.empty()) {
		int best = (*s.begin()).first;
		int u = (*s.begin()).second;
		s.erase(s.begin());
		for (int i = 0; i < g[u].size(); i++) {
			v = g[u][i].first, w = g[u][i].second;

			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				s.insert({ dist[v], v });
				node[v] = u;
			}
		}
	}

	if (dist[n] == inf)
		cout << -1 << endl;
	else
		printPath(n);

	return 0;
}
