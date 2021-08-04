#include "bits/stdc++.h"

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e15;

int n, m, E, dist[14][14], energy[14][14];
int dp[14][1 << 14][101];

int go(int from, int mask, int spent) {
	if (spent > E) return inf;
	int vis = __builtin_popcountll(mask);
	if (vis == n)
		return 0;
	int &ans = dp[from][mask][spent];
	if (~ans)
		return ans;
	ans = inf;

	for (int to = 0; to < n; to++) if ((mask >> to & 1) == 0) {
		if (~energy[from][to]) {
			assert(dist[from][to] > 0);
			int get = dist[from][to] + go(to, mask | (1 << to), spent + energy[from][to]);
			ans = min(ans, get);
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	memset(energy, -1, sizeof(energy));
	memset(dp, -1, sizeof(dp));
	cin >> n >> m >> E;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;	 --u, --v;
		int d, e;
		cin >> d >> e;
		dist[u][v] = dist[v][u] = d;
		energy[u][v] = energy[v][u] = e;
	}
	int ans = go(0, 1, 0);
	cout << (ans >= inf ? -1 : ans);
}