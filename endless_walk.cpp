/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 13 April 2022 10:13:01 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5;
int N, M;
vector<int> g[_];
bool cycle[_], vis[_], in_stack[_];

bool check_cycle(int u) {
	if (vis[u]) {
		in_stack[u] = false;
		return false;
	}
	vis[u] = true;
	in_stack[u] = true;
	for (int v : g[u]) {
		if (!vis[v] && check_cycle(v)) {
			cycle[v] = true;
			return true;
		} else if (in_stack[v]) {
			cycle[v] = true;
			return true;
		}
	}
	in_stack[u] = false;
	return false;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	int ans = 0;
	FOR(i, 1, N) {
		if (!vis[i]) {
			if (check_cycle(i)) {
				cycle[i] = true;
			}
		}
		if (cycle[i]) {
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
