/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 12:29:14 PM IST
(ツ) Criticism is something you can easily avoid by saying nothing, doing nothing, and being nothing.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, LOG = 22;

int n, tin[N], tout[N], tim;
int par[LOG + 1][N];
std::vector<int> g[N];
array<int,2> edge[N];
int dep[N];
 
void dfs0(int u, int p, int dist = 1) {
	tin[u] = ++tim;
	dep[u] = dist;
	par[0][u] = p;
	FOR(i,1,LOG) {
		par[i][u] = par[i - 1][par[i - 1][u]];
	}
	for (int v : g[u]) if (p ^ v) dfs0(v, u, dist + 1);
	tout[u] = tim;
}
 
bool isAncestor(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u]; 
}
 
int LCA(int u, int v) {
	if (isAncestor(u, v)) return u;
	if (isAncestor(v, u)) return v;
 
	for (int i = LOG; ~i; --i) {
		if (!isAncestor(par[i][u], v))
			u = par[i][u];
	}
	assert(isAncestor(par[0][u], v));
	return par[0][u];
}

int dist(int u, int v) {
	return dep[u] + dep[v] - 2 * dep[LCA(u, v)];
}

bool valid(int u, int v) {
	assert(dep[u] <= dep[v]);
	return dist(LCA(u, v), u) <= 1;
}
 
int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int Q;
	cin >> n >> Q;
	FOR(i,2,n) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs0(1,1,1);

	while (Q--) {
		int k;	cin >> k;
		vector<int> given(k);
		int farthest = -1;
		int maxDist = -1;

		for (int &x : given) {
			cin >> x;
			if (dep[x] > maxDist) {
				maxDist = dep[x];
				farthest = x;
			}
		}

		assert(~farthest && ~maxDist);
		bool ok = true;

		for (int &x : given) {
			ok &= valid(x, farthest);
		}
		cout << (ok ? "YES" : "NO") << "\n";
	}
}