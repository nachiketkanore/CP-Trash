#include <bits/stdc++.h>

#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int N = 5e5 + 5;

int n, ans[N], a[N], dis[N];
vector<int> g[N], val_nodes[N];

void dfs(int u, int par = 1, int dist = 1) {
	val_nodes[a[u]].push_back(u);

	dis[u] = dist;

	for (int v : g[u]) if (par^v) dfs(v, u, dist + 1);

	val_nodes[a[u]].pop_back();

	int best = -1, best_dist = -1;

	FOR (val,1,100) if (__gcd(a[u], val) == 1) {
		if (sz(val_nodes[val]) == 0) continue;
		int who = val_nodes[val].back();
		if (dis[who] > best_dist) {
			best_dist = dis[who];
			best = who;
		}
	}
	ans[u] = best;
}

void solve() {
	cin >> n;
	FOR (i,1,n) {
		g[i].clear();
		dis[i] = 0;
		ans[i] = -1;
	}
	FOR (i,1,n) cin >> a[i];
	F0R (i,n-1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	
	FOR (i,1,n) cout << ans[i] << " \n"[i==n];

	FOR (i,1,100) val_nodes[i].clear();
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) solve();
}

