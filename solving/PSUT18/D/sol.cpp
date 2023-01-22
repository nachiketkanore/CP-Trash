/*
Author: Nachiket Kanore
Created: Thursday 17 December 2020 04:30:53 PM IST
(ツ) Weve got to have a dream if we are going to make a dream come true.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size> ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}
template <typename A, typename B> ostream& operator<<(ostream& os, const map<A, B>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) {
	return uniform_int_distribution<int>(a, b)(mt_rng);
}

template <int D, typename T> struct vec : public vector<vec<D - 1, T>> {
	static_assert(D >= 1, "Dimensions invalid");
	template <typename... Args> vec(int n = 0, Args... args) : vector<vec<D - 1, T>>(n, vec<D - 1, T>(args...)) {
	}
};
template <typename T> struct vec<1, T> : public vector<T> {
	vec(int n = 0, const T& val = T()) : vector<T>(n, val) {
	}
};

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e5 + 5, inf = 1e18;

int n;
vector<int> g[N];
bool vis[N];
int max_dep;
vector<int> comp;
int ans[N];
int pp[N], out[N];
int dep[N];

void dfs(int u, int par, int dep) {
	::dep[u] = dep;
	vis[u] = true;
	comp.push_back(u);
	cmax(max_dep, dep);
	for (int v : g[u])
		if (!vis[v] && v != par)
			dfs(v, u, dep + 1);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	n = rand(1, 5);
	cin >> n;

	FOR(i, 1, n) {
		int p = rand(0, i - 1);
		cin >> p;
		pp[i] = p;
		if (p > 0) {
			out[p]++;
			g[p].push_back(i);
		}
	}

	int start = 1;
	max_dep = 0;

	FOR(i, 1, n) if (pp[i] == 0) {
		comp.clear();
		dfs(i, i, 1);
		vector<int> leafs;
		for (int x : comp) {
			if (out[x] == 0)
				leafs.push_back(x);
			vis[x] = false;
		}

		sort(ALL(leafs), [&](int u, int v) { return dep[u] > dep[v]; });

		for (int leaf : leafs) {
			do {
				vis[leaf] = 1;
				ans[leaf] = start++;
				leaf = pp[leaf];
			} while (leaf > 0 && !vis[leaf]);
		}
	}

	FOR(i, 1, n) assert(vis[i]);
	set<int> f;
	FOR(i, 1, n) {
		f.insert(ans[i]);
		assert(1 <= ans[i] && ans[i] <= n);
	}
	assert(sz(f) == n);

	FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}
