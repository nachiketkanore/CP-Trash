/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 24 May 2022 02:17:11 PM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

class DSU_with_rollbacks {
	private:
	int N;
	vector<int> par, rank, ops;

	public:
	DSU_with_rollbacks(int N) : N(N) {
		par.resize(N + 1);
		rank.resize(N + 1);
		FOR(i, 1, N) {
			par[i] = i;
			rank[i] = 1;
		}
	}

	int find(int i) {
		return par[i] == i ? i : find(par[i]);
	}

	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		if (rank[a] > rank[b])
			swap(a, b);
		ops.push_back(a);
		par[a] = b;
		rank[b] += rank[a];
	}

	void roll_back(int T) {
		while (ops.size() > T) {
			int i = ops.back();
			ops.pop_back();
			rank[par[i]] -= rank[i];
			par[i] = i;
		}
	}

	int get_size(int u) {
		return rank[find(u)];
	}

	int performed() {
		return (int)ops.size();
	}
};

int answer = 0;
vector<vector<pair<int, int>>> edges;

void go(int L, int R, DSU_with_rollbacks& DSU) {
	if (L > R)
		return;
	if (L == R) {
		for (auto [u, v] : edges[L]) {
			answer += DSU.get_size(u) * DSU.get_size(v);
		}
		return;
	}

	int mid = (L + R) / 2;
	int revert = DSU.performed();

	FOR(id, mid + 1, R) {
		for (auto [u, v] : edges[id]) {
			DSU.merge(u, v);
		}
	}
	go(L, mid, DSU);
	DSU.roll_back(revert);

	FOR(id, L, mid) {
		for (auto [u, v] : edges[id]) {
			DSU.merge(u, v);
		}
	}
	go(mid + 1, R, DSU);
	DSU.roll_back(revert);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	edges.resize(N + 1);
	DSU_with_rollbacks DSU(N);

	F0R(i, N - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[w].push_back(make_pair(u, v));
	}

	go(1, N, DSU);
	cout << answer << '\n';
	return 0;
}
