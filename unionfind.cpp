#include <bits/stdc++.h>
using namespace std;

class UnionFind {
	public:
	int N, components;
	vector<int> parent, ranks;

	UnionFind(int N_) {
		N = N_;
		parent.resize(N + 1);
		ranks.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			ranks[i] = 1;
		}
		components = N;
	}
	int find(int u) {
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}
	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v)
			return false;
		if (ranks[u] < ranks[v])
			swap(u, v);
		parent[v] = u;
		ranks[u] += ranks[v];
		ranks[v] = 0;
		components--;
		return true;
	}
	bool same(int u, int v) {
		return find(u) == find(v);
	}
	int groupSize(int u) {
		return ranks[find(u)];
	}
};

int main() {
	return 0;
}
