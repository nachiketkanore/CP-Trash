#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = L; i <= R; i++)
using namespace std;

const int N = 3e5 + 5, inf = 1e18;

struct FenwickTree {
	vector<int> bit; // binary indexed tree
	int n;

	FenwickTree(int n) {
		this->n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<int> a) : FenwickTree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	int sum(int r) {
		int ret = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	int sum(int l, int r) {
		if (l > r)
			return 0;
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
} tree(N + 5);

int n, a[N], b[N], ans;
std::vector<int> g[N];

void compress() {
	vector<int> all;

	FOR(i, 1, n) all.push_back(a[i]);
	FOR(i, 1, n) all.push_back(b[i]);
	sort(all.begin(), all.end());

	FOR(i, 1, n) a[i] = (lower_bound(all.begin(), all.end(), a[i]) - all.begin()) + 10;
	FOR(i, 1, n) b[i] = (lower_bound(all.begin(), all.end(), b[i]) - all.begin()) + 10;
}

void dfs(int u, int par) {
	int val = min(a[u], b[u]);
	ans += tree.sum(0, val - 1);

	int add = max(a[u], b[u]);
	tree.add(add, 1);

	for (int v : g[u])
		if (v ^ par)
			dfs(v, u);

	tree.add(add, -1);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];

	compress();

	dfs(1, 0);

	cout << ans;
}