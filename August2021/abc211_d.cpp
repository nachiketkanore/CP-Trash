/**
 *    Author: Nachiket Kanore
 *    Created: Friday 20 August 2021 05:24:14 PM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
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

int32_t main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N, vector<int>());
	vector<int> dist(N, -1), ways(N);
	const int MOD = 1e9 + 7;
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	queue<int> Q;
	Q.push(0);
	dist[0] = 0;
	ways[0] = 1;

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int v : G[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				Q.push(v);
				ways[v] = ways[u];
			} else if (dist[v] == dist[u] + 1) {
				ways[v] += ways[u];
				if (ways[v] >= MOD)
					ways[v] -= MOD;
			}
		}
	}
	cout << ways.back() << '\n';
}
