/*
Author: Nachiket Kanore
Created: Friday 30 October 2020 10:53:59 AM IST
(ツ) A garden is always a series of losses set against a few triumphs, like life itself.
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
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

struct FlowEdge {
	int v, u;
	long long cap, flow = 0;
	FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {
	}
};

struct Dinic {
	const long long flow_inf = 1e18;
	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Dinic(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	void add_edge(int v, int u, long long cap) {
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap - edges[id].flow < 1)
					continue;
				if (level[edges[id].u] != -1)
					continue;
				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}

	long long dfs(int v, long long pushed) {
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;
		for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
				continue;
			long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0)
				continue;
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}

	long long flow() {
		long long f = 0;
		while (true) {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs())
				break;
			fill(ptr.begin(), ptr.end(), 0);
			while (long long pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
};

const int N = 110, inf = 69;
int a[N], from[N], to[N];
vector<int> primes;

void add_primes(int val) {
	for (int d = 2; d * d <= val; d++)
		if (val % d == 0) {
			primes.push_back(d);
			while (val % d == 0)
				val /= d;
		}
	if (val > 1)
		primes.push_back(val);
}

void make_unique() {
	sort(primes.begin(), primes.end());
	vector<int> nxt;

	for (int i = 0; i < sz(primes); i++) {
		if (i == 0 || nxt.back() != primes[i]) {
			nxt.push_back(primes[i]);
		}
	}

	primes = nxt;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	FOR(i, 1, n) {
		cin >> a[i];
		add_primes(a[i]);
	}

	make_unique();

	FOR(i, 1, m) {
		cin >> from[i] >> to[i];
		if (from[i] % 2 == 0)
			swap(from[i], to[i]);
	}

	int ans = 0;

	for (int prime : primes) {

		int source = n + 2, sink = n + 3;
		Dinic flow(n + 5, source, sink);

		// odd to the left, edge with source
		FOR(i, 1, n) if (i & 1) {
			int cost = 0;
			int x = a[i];
			while (x % prime == 0)
				x /= prime, ++cost;
			flow.add_edge(source, i, cost);
		}

		// even to the right, edge with sink
		FOR(i, 1, n) if (i % 2 == 0) {
			int cost = 0;
			int x = a[i];
			while (x % prime == 0)
				x /= prime, ++cost;
			flow.add_edge(i, sink, cost);
		}

		// middle edges between bipartite components
		FOR(i, 1, m) {
			flow.add_edge(from[i], to[i], inf);
		}

		ans += flow.flow();
	}

	cout << ans << "\n";
}
