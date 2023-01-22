/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 29 August 2021 03:45:43 PM IST
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

const int _ = 55, LG = 20;
int N, C[_], parent[LG][_], level[_], pref[_];
vector<int> g[_];

void dfs(int k, int par, int lvl, int sum = 0) {
	parent[0][k] = par;
	pref[k] = sum + C[k];

	level[k] = lvl;
	for (auto it : g[k]) {
		if (it == par)
			continue;
		dfs(it, k, lvl + 1, pref[k]);
	}
}

void precompute() {
	for (int i = 1; i < LG; i++)
		for (int j = 1; j <= N; j++)
			if (parent[i - 1][j])
				parent[i][j] = parent[i - 1][parent[i - 1][j]];
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
void solve() {
	memset(parent, 0, sizeof(parent));
	memset(level, 0, sizeof(level));
	memset(pref, 0, sizeof(pref));
	memset(C, 0, sizeof(C));
	cin >> N;
	FOR(i, 1, N) {
		cin >> C[i];
		g[i].clear();
	}
	F0R(i, N - 1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1, 1);
	precompute();
	int ans = 0;
	FOR(i, 1, N) {
		cmax(ans, pref[i]);
	}
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			if (LCA(i, j) == 1) {
				cmax(ans, pref[i] + pref[j] - C[1]);
			}
		}
	}
	if (ans == 0) {
		FOR(i, 1, N) assert(!C[i]);
	}
	cout << ans << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}
}
