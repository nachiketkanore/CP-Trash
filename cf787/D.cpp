/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 May 2022 07:54:19 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5;
int N, root, par[_], sub[_];
bool vis[_];
vector<int> g[_];

void dfs(int u, int par = root) {
	sub[u] = 1;
	for (int v : g[u]) {
		if (v ^ par) {
			dfs(v, u);
			sub[u] += sub[v];
		}
	}
}

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		g[i].clear();
		sub[i] = 0;
		par[i] = -1;
		vis[i] = false;
	}
	root = -1;
	FOR(i, 1, N) {
		cin >> par[i];
		if (i == par[i]) {
			root = i;
		} else {
			int u = i, v = par[i];
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	dfs(root, root);
	vector<int> leaves;
	FOR(i, 1, N) {
		if (sub[i] == 1) {
			leaves.push_back(i);
		}
	}
	cout << sz(leaves) << '\n';
	for (int leaf : leaves) {
		vector<int> path;
		int curr = leaf;
		while (true) {
			if (vis[curr])
				break;
			vis[curr] = true;
			path.push_back(curr);
			curr = par[curr];
		}
		cout << sz(path) << '\n';
		reverse(ALL(path));
		for (int node : path) {
			cout << node << ' ';
		}
		cout << '\n';
	}
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
