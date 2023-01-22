/*
Author: Nachiket Kanore
Created: Tuesday 16 February 2021 10:54:54 AM IST
(ツ) Happiness is a sunset - it is there for all, but most of us look the other way and lose it.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define int long long
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 2e6 + 5, inf = 1e8;

int n, m;
vector<pair<int, int>> g[N];

void dijkstra(int s, vector<int>& d) {

	d[s] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({ 0, s });
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : g[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({ d[to], to });
			}
		}
	}
}

int solve(vector<vector<int>> mat) {
	n = mat.size();
	m = mat[0].size();

	auto inside = [&](int i, int j) { return i >= 1 && i <= n && j >= 1 && j <= m; };

	auto node = [&](int i, int j) {
		assert(inside(i, j));
		return (i - 1) * m + j;
	};

	int to = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int val = mat[i - 1][j - 1];
			if (val == 9)
				to = node(i, j);
		}
	}

	assert(~to);
	vector<int> dx = { 1, -1, 0, 0 };
	vector<int> dy = { 0, 0, 1, -1 };

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int val = mat[i - 1][j - 1];
			if (val == 1) {
				int u = node(i, j);
				for (int k = 0; k < 4; k++) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if (inside(ni, nj) && mat[ni - 1][nj - 1] != 0) {
						int v = node(ni, nj);
						g[u].push_back({ v, 1 });
						g[v].push_back({ u, 1 });
					}
				}
			}
		}
	}

	const int tot = n * m + 3;
	std::vector<int> dist(tot, inf);
	dijkstra(1, dist);
	int ans = dist[to];
	if (ans >= inf)
		ans = -1;

	for (int i = 0; i <= tot; i++)
		g[i].clear();
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T = 3;
	while (T--) {
		vector<vector<int>> mat = { { 1, 1, 1 }, { 1, 0, 1 }, { 1, 9, 1 } };
		cout << solve(mat) << '\n';
	}
}
