/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 06 February 2022 12:07:21 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5;

vector<int> g[N];
vector<int> subtree[N];

void merge(int par, int child) {
	for (int v: subtree[child]) {
		subtree[par].push_back(v);
	}
	sort(subtree[par].begin(), subtree[par].end());
	subtree[child].clear();
}

void dfs(int u, int par) {
	subtree[u].push_back(u);
	for (int v: g[u]) {
		if (v != par) {
			dfs(v, u);
			merge(u, v);
		}
	}
	// now subtree[u] is sorted vector of all nodes in subtree of u
}

int32_t main() {
	dfs(1, 0);
	return 0;
}
