/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 06:45:30 PM IST
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

int N, M;
const int _ = 2e5 + 5;

struct DSU {
	int connected;
	int par[_], sz[_];

	void init(int n) {
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

	int getSize(int k) {
		return sz[getPar(k)];
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
} dsu;

bool satisfies(const vector<array<int, 3>>& edges) {
	dsu.init(N);
	for (auto [u, v, _] : edges)
		dsu.unite(u, v);
	return dsu.connected == 1;
}

int go(int bit, const vector<array<int, 3>>& edges) {
	if (bit == -1)
		return 0;
	vector<array<int, 3>> unset_edges;
	for (auto [u, v, w] : edges) {
		if ((w >> bit & 1) == 0) {
			unset_edges.push_back({ u, v, w });
		}
	}
	if (satisfies(unset_edges)) {
		return go(bit - 1, unset_edges);
	} else {
		assert(satisfies(edges));
		return (1ll << bit) + go(bit - 1, edges);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		vector<array<int, 3>> edges(M);
		for (auto& [u, v, w] : edges)
			cin >> u >> v >> w;
		cout << go(32, edges) << '\n';
	}

	return 0;
}
