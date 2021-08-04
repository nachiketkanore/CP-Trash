#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

int32_t main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n+1);
	vector<bool> vis(n+1, false);
	FOR (i,2,n) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> bfs(n);
	for (int &u : bfs) cin >> u;
	vector<vector<int>> levels;
	vector<int> curr_level = {1};
	while (sz(curr_level)) {
		vector<int> next_level;
		for (int u : curr_level) vis[u] = true;
		levels.push_back(curr_level);
		for (int u : curr_level) 
			for (int v : g[u]) 
				if (!vis[v]) next_level.push_back(v);
		curr_level = next_level;
	}
	bool ok = true;
	while (sz(levels)) {
		vector<int> get;
		curr_level = levels.back();
		levels.pop_back();
		while (sz(get) ^ sz(curr_level)) {
			get.push_back(bfs.back());
			bfs.pop_back();
		}
		sort(ALL(get));
		sort(ALL(curr_level));
		ok &= get == curr_level;
	}
	cout << (ok ? "Yes" : "No") << '\n';
}

