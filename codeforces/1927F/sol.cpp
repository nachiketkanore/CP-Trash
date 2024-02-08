/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 08 February 2024 08:36:14 PM IST
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
struct DSU {
	int connected;
	vector<int> par, sz;

	DSU(int n) {
		par.resize(n + 1);
		sz.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		connected = n;
	}

	int getPar(int k) {
		while (k != par[k]) {
			par[k] = par[par[k]];
			k = par[k];
		}
		return k;
	}

	bool same(int u, int v) {
		return (getPar(u) == getPar(v));
	}

	bool unite(int u, int v) {
		int par1 = getPar(u), par2 = getPar(v);

		if (par1 == par2)
			return false;

		connected--;

		if (sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
		return true;
	}
};

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<array<int, 3>> edges(M);
		for (auto& [u, v, w] : edges)
			cin >> u >> v >> w;
		sort(ALL(edges), [&](auto a, auto b) { return a[2] > b[2]; });

		int ans = -1, e1 = -1, e2;
		DSU dsu(N);
		map<int, vector<int>> adj;
		for (auto& [u, v, w] : edges) {
			if (dsu.same(u, v)) {
				ans = w;
				e1 = u, e2 = v;
			} else {
				adj[u].push_back(v);
				adj[v].push_back(u);
				dsu.unite(u, v);
			}
		}
		assert(~e1);

		set<int> visited;
		vector<int> cycle;
		queue<int> Q;
		Q.push(e1);
		map<int, int> parent;
		while (!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			visited.insert(curr);
			for (int v : adj[curr]) {
				if (!visited.count(v)) {
					Q.push(v);
					parent[v] = curr;
				}
			}
		}
		assert(visited.count(e2));
		while (e2 ^ e1) {
			cycle.push_back(e2);
			e2 = parent[e2];
		}
		cycle.push_back(e1);
		assert(~ans);
		assert(!cycle.empty());
		cout << ans << ' ' << sz(cycle) << '\n';
		for (int u : cycle) {
			cout << u << ' ';
		}
		cout << '\n';
	}

	return 0;
}
