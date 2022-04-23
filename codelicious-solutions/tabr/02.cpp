#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	assert(n >= 2);
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> depth(n);
	vector<int> leaf(n, 1);
	vector<int> pv(n);
	function<void(int, int)> Dfs = [&](int v, int p) {
		pv[v] = p;
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			leaf[v] = 0;
			depth[to] = depth[v] + 1;
			Dfs(to, v);
		}
	};
	Dfs(0, -1);
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(),
	[&](int i, int j) { return depth[i] > depth[j]; });
	long long ans = 0;
	for (int i : order) {
		if (leaf[i]) {
			continue;
		}
		vector<long long> c(1);
		for (int j : g[i]) {
			if (j != pv[i]) {
				c.emplace_back(a[j]);
			}
		}
		if (*max_element(c.begin(), c.end()) <= a[i]) {
			a[i] = 0;
			continue;
		}
		if (i == 0) {
			ans = max(*max_element(c.begin(), c.end()) - a[0], 0LL);
		}
		a[i] = accumulate(c.begin(), c.end(), 0);
	}
	cout << ans << '\n';
	return 0;
}
