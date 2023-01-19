#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, t;
	cin >> n >> q >> t;
	vector<vector<int>> g(n + 1);
	vector<bool> vis;

	function<void(int)> dfs = [&](int u) {
		if (vis[u])
			return;
		vis[u] = 1;
		for (int v : g[u])
			dfs(v);
	};
	int ans = 0;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, v;
			cin >> u >> v;
			u = (u ^ (t * ans)) % n + 1;
			v = (v ^ (t * ans)) % n + 1;
			g[u].push_back(v);
		} else {
			int x;
			cin >> x;
			x = (x ^ (t * ans)) % n + 1;
			vis = vector<bool>(n + 1, false);
			dfs(1);
			if (vis[x])
				ans = x;
			else
				ans = 0;
			cout << ans << '\n';
		}
	}
}
