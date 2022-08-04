/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 26 July 2022 02:52:00 PM IST
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

const int _ = 1e5 + 5;
const int N = 2e5 + 5, LG = 19;

int tim = 0;
int parent[LG][N];
int tin[N], tout[N], level[N], subtree_size[N];
std::vector<int> g[N];
int n, q;

void dfs(int k, int par, int lvl) {
	tin[k] = ++tim;
	parent[0][k] = par;
	level[k] = lvl;
	subtree_size[k] = 1;
	for (auto it : g[k]) {
		if (it == par)
			continue;
		dfs(it, k, lvl + 1);
		subtree_size[k] += subtree_size[it];
	}
	tout[k] = tim;
}

void precompute() {
	for (int i = 1; i < LG; i++)
		for (int j = 1; j <= n; j++)
			if (parent[i - 1][j])
				parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int kthAncestor(int u, int k) {
	for (int i = 0; i < LG; i++) {
		if (k >> i & 1) {
			u = parent[i][u];
		}
	}
	return u;
}

int LCA(int u, int v) {
	if (level[u] < level[v])
		swap(u, v);
	int diff = level[u] - level[v];
	for (int i = LG - 1; i >= 0; i--) {
		if ((1 << i) & diff) {
			u = parent[i][u];
		}
	}
	if (u == v)
		return u;
	for (int i = LG - 1; i >= 0; i--) {
		if (parent[i][u] && parent[i][u] != parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}

int get_distance(int u, int v) {
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

int kthOnPath(int u, int v, int k) {
	int uv = LCA(u, v);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// not working
	cin >> n;
	F0R(i, n - 1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 1, 1);
	precompute();

	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		int dist = get_distance(x, y);
		if (dist % 2 == 1) {
			cout << "0\n";
		} else {
			if (dist == 0) {
				cout << n << '\n';
			} else {
				// dist : {2, 4, 6, 8, }
				int mid = dist / 2;
			}
		}
	}

	return 0;
}
