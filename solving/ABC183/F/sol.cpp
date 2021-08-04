/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:25:22 PM IST
(ツ) The biggest adventure you can ever take is to live the life of your dreams.
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <map>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, Q, c[N], par[N], sizes[N];
map<int,int> f[N];

int find(int u) {
	if (u == par[u])
		return u;
	return u = find(par[u]);
}

void unite(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (sz(f[u]) < sz(f[v]))
		swap(u, v);
	// merge smaller to larger, u > v
	par[v] = u;
	for (auto &it : f[v]) {
		f[u][it.first] += it.second;
	}
	f[v].clear();
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> Q;

	FOR (i,1,n) {
		cin >> c[i];
		par[i] = i;
		sizes[i] = 1;
		f[i][c[i]] = 1;
	}

	while (Q--) {
		int type;	cin >> type;
		if (type == 1) {
			int a, b;
			cin >> a >> b;
			unite(a, b);
		} else {
			int x, y;
			cin >> x >> y;
			x = find(x);
			cout << f[x][y] << "\n";
		}
	}	
}
