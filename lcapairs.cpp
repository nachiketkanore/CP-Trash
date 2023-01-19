/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 11 November 2021 03:12:18 PM IST
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

const int _ = 1e5 + 5;
int N, Q, sub[_];
vector<int> g[_];

void dfs(int u = 1) {
	sub[u] = 1;
	for (int v : g[u]) {
		dfs(v);
		sub[u] += sub[v];
	}
}

int32_t main() {
	cin >> N >> Q;
	FOR(i, 2, N) {
		int par;
		cin >> par;
		g[par].push_back(i);
	}
	dfs();
	while (Q--) {
		int root;
		cin >> root;
		int ans = sub[root];
		int sum = 0;
		for (int v : g[root]) {
			ans += sub[v] * sum;
			sum += sub[v];
		}
		cout << ans << '\n';
	}
}
