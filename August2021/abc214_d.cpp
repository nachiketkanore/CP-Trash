/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 21 August 2021 01:53:02 AM IST
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

struct edge {
	int u, v, w;
	edge(int u, int v, int w) : u(u), v(v), w(w) {
	}
	bool operator<(const edge& other) const {
		return w < other.w;
	}
};

struct DSU {
	int N;
	vector<int> par, rank;
	DSU(int N) : N(N) {
		par = vector<int>(N);
		rank = vector<int>(N);
		F0R(i, N) {
			par[i] = i;
			rank[i] = 1;
		}
	}
	int find(int u) {
		if (u == par[u])
			return u;
		return par[u] = find(par[u]);
	}
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v)
			return false;
		par[v] = u;
		rank[u] += rank[v];
		return true;
	}
	int get_size(int u) {
		u = find(u);
		return rank[u];
	}
};

int32_t main() {
	int N;
	cin >> N;
	DSU dsu(N);
	vector<edge> edges;
	F0R(i, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges.push_back(edge(u, v, w));
	}
	sort(ALL(edges));
	int ans = 0;
	for (const edge& e : edges) {
		ans += e.w * dsu.get_size(e.u) * dsu.get_size(e.v);
		assert(dsu.unite(e.u, e.v));
	}
	cout << ans << '\n';
}
