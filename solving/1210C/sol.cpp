/*
Author: Nachiket Kanore
Created: Tuesday 29 December 2020 05:07:16 PM IST
(ツ) Show up, show up, show up, and after a while the muse shows up, too.
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

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 1e5, mod = 1e9 + 7;

long long gcd(long long a, long long b) {
	if (a == 0 && b == 0)
		return 0;
	return b == 0 ? a : gcd(b, a % b);
}

int n, val[N + 1], ans;
vector<int> g[N + 1];
map<int, int> anc_gcds[N + 1];

void dfs(int u, int par) {
	for (auto [G, CNT] : anc_gcds[u])
		ans = (ans + G * CNT) % mod;
	for (int v : g[u])
		if (v ^ par) {
			for (auto [G, CNT] : anc_gcds[u]) {
				int nxt_G = gcd(G, val[v]);
				anc_gcds[v][nxt_G] += CNT;
			}
			anc_gcds[v][val[v]]++;
			dfs(v, u);
		}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) cin >> val[i];
	FOR(i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	anc_gcds[1][val[1]]++;
	dfs(1, 0);
	cout << ans;
}
