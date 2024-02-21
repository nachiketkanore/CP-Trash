/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 21 February 2024 11:02:50 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 1e5 + 5;
vector<int> adj[_], component;
bool visited[_];
int N;
string S;

void dfs(int u, int par) {
	if (S[u] == 'P' || visited[u])
		return;
	component.push_back(u);
	visited[u] = true;
	for (int v : adj[u])
		if (v ^ par)
			dfs(v, u);
}

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		adj[i].clear();
		visited[i] = false;
	}
	FOR(i, 2, N) {
		int u;
		cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}
	cin >> S;
	S = "$" + S;
	int ans = 0;

	FOR(i, 1, N) {
		if (S[i] == 'S' && !visited[i]) {
			component.clear();
			dfs(i, i);

			for (int u : component) {
				for (int v : adj[u]) {
					if (S[v] == 'P')
						++ans;
				}
			}
		}
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
