/**
 *    Author: Nachiket Kanore
 *    Created: Monday 09 August 2021 03:52:12 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

int N;
vector<int> g[200005], path;

void dfs(int u, int par) {
	path.push_back(u);
	for (int v : g[u]) {
		if (v == par)
			continue;
		dfs(v, u);
		path.push_back(u);
	}
	// if (sz(g[u]) > 1)
	// path.push_back(u);
}

int32_t main() {
	cin >> N;
	FOR(i, 1, N - 1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	FOR(i, 1, N) {
		sort(ALL(g[i]));
	}
	dfs(1, 1);
	for (int x : path) {
		cout << x << ' ';
	}
}
