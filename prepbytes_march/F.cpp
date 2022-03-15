/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 15 March 2022 03:25:21 PM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int _= 1e5 + 5;
int N, C, root, sub[_];
vector<pair<int,int>> g[_];
vector<int> vals;

void dfs(int u, int par) {
	sub[u] = 1;
	for (auto edge: g[u]) {
		int v = edge.first, w = edge.second;
		if (v ^ par) {
			dfs(v, u);
			sub[u] += sub[v];
		}
	}
	for (auto edge: g[u]) {
		int v = edge.first, w = edge.second;
		if (v ^ par) {
			// u to v edge has weight w
			vals.push_back(sub[v] * w);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> C >> root;
		vals.clear();
		for (int i = 1; i <= N; i++) {
			g[i].clear();
			sub[i] = 0;
		}
		for (int i = 1, u, v, w; i < N; i++) {
			cin >> u >> v >> w;
			g[u].push_back(make_pair(v, w));
			g[v].push_back(make_pair(u, w));
		}
		dfs(root, root);
		sort(vals.begin(), vals.end());
		while (C--) {
			vals.pop_back();
		}
		int ans = 0;
		for (int val: vals) {
			ans += val;
		}
		cout << ans << '\n';
	}
	return 0;
}
