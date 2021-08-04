#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n, val[N];
vector<pair<int,int>> g[N];

void dfs(int u, int par, int dist) {
	val[u] = dist;
	for (auto [v,w] : g[u]) if (v != par) dfs(v, u, dist + w);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	int tot = 0;
	FOR(i,1,n-1) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
		tot += w;
	}
	dfs(1,0,0);
	int ans = inf;
	FOR(i,1,n) {
		ans = min(ans, 2*tot - val[i]);
	}
	cout << ans;
}