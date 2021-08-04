/*
Author: Nachiket Kanore
Created: Saturday 31 October 2020 11:57:23 AM IST
(ツ) We must overcome the notion that we must be regular. It robs you of the chance to be extraordinary and leads you to the mediocre.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <set>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, m1, m2, par[N], compSize[N];
set<int> g[N];

int find(int u) {
	if (u == par[u])
		return u;
	return u = find(par[u]);
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	compSize[u] += compSize[v];
	par[v] = u;
	compSize[v] = 0;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m1 >> m2;

	FOR (i,1,n) {
		par[i] = i;
		compSize[i] = 1;
	}

	FOR (i,1,m1) {
		int u, v;
		cin >> u >> v;
		g[u].insert(v);
		g[v].insert(u);
	}

	FOR (i,1,m2) {
		int u, v;
		cin >> u >> v;
		if (g[u].count(v) || g[v].count(u)) unite(u, v);
	}

	FOR (i,1,n) cout << compSize[find(i)] << " \n"[i == n];
}
