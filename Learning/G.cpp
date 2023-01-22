/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 August 2021 01:31:34 AM IST
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

int32_t main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<vector<int>> graph(N);
		F0R(i, N - 1) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		vector<bool> vis(N, false);
		vector<int> level = { 0 };
		vector<int> depth(N);
		depth[0] = 1;

		while (sz(level)) {
			vector<int> next_level;

			for (int u : level) {
				vis[u] = true;
				for (int v : graph[u]) {
					if (vis[v])
						continue;
					depth[v] = depth[u] + 1;
					next_level.push_back(v);
				}
			}
			level = next_level;
		}
		F0R(i, N) cout << depth[i] << " \n"[i == N - 1];
	}
}
