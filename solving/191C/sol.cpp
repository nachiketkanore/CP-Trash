/*
Author: Nachiket Kanore
Created: Wednesday 14 October 2020 10:12:58 PM IST
(ツ) Life is not measured by the breaths you take, but by its breathtaking moments.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;
const int LOG = 22;

int n, k, subtreeSum[N], tin[N], tout[N], tim;
int par[LOG + 1][N];
std::vector<int> g[N];
array<int, 2> edge[N];
int dep[N];

void dfs0(int u, int p) {
	tin[u] = ++tim;
	par[0][u] = p;
	FOR(i, 1, LOG) {
		par[i][u] = par[i - 1][par[i - 1][u]];
	}
	for (int v : g[u])
		if (p ^ v)
			dfs0(v, u);
	tout[u] = tim;
}

bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int LCA(int u, int v) {
	if (isAncestor(u, v))
		return u;
	if (isAncestor(v, u))
		return v;

	for (int i = LOG; ~i; --i) {
		if (!isAncestor(par[i][u], v))
			u = par[i][u];
	}
	assert(isAncestor(par[0][u], v));
	return par[0][u];
}

int dfs(int u, int p, int dist = 1) {
	dep[u] = dist;
	int& ans = subtreeSum[u];
	for (int v : g[u])
		if (p ^ v) {
			ans += dfs(v, u, dist + 1);
		}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int u, v;
	cin >> n;
	FOR(i, 2, n) {
		cin >> u >> v;
		edge[i] = { u, v };
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs0(1, 1);
	cin >> k;
	FOR(i, 1, k) {
		cin >> u >> v;
		subtreeSum[u]++;
		subtreeSum[v]++;
		subtreeSum[LCA(u, v)] -= 2;
	}
	dfs(1, 1);
	FOR(i, 2, n) {
		u = edge[i][0], v = edge[i][1];
		if (dep[u] < dep[v])
			swap(u, v);
		cout << subtreeSum[u] << " \n"[i == n];
	}
}
