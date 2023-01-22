/*
Author: Nachiket Kanore
Created: Friday 30 October 2020 07:17:08 PM IST
(ツ) It is impossible to feel grateful and depressed in the same moment.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
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

const int N = 100 + 5, inf = 1e18;

int n, m, dist[N][N];
array<int, 3> edges[N * N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = inf, dist[i][i] = 0;

	FOR(i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = { u, v, w };
		dist[u][v] = dist[v][u] = w;
	}

	FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int ans = 0;

	FOR(i, 1, m) {
		auto [u, v, w] = edges[i];

		bool yes = false;

		FOR(a, 1, n) FOR(b, 1, n) if (a != b) {
			int best = dist[a][b];
			see(a, b, best);
			if (dist[a][u] + dist[v][b] + w == best)
				yes = true;
			if (dist[b][u] + dist[v][a] + w == best)
				yes = true;
		}

		if (!yes) {
			see(u, v, w);
			++ans;
		}
	}

	cout << ans << "\n";
}
