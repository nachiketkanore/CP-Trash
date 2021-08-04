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

// source: https://cp-algorithms.com/graph/lca_binary_lifting.html
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, height;
vector<vector<int>> up;

void dfs(int v, int p, int dist = 1)
{
    tin[v] = ++timer;
	height[v] = dist;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v, dist + 1);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int get_dist(int u, int v) {
	return height[u] + height[v] - 2 * height[lca(u, v)];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    height.resize(n);
    timer = 0;
    l = ceil(log2(n)) + 2;
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

void solve() {
	int Q;
	cin >> n >> Q;
	adj = vector<vector<int>>(n);
	F0R (i,n-1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	preprocess(0);

	while (Q--) {
		int K, D, ans = 0;
		cin >> K >> D;
		vector<int> nodes(K);
		for (int &u: nodes) cin >> u, --u;
		for (int i = 0; i < K; i++)
			for (int j = i + 1; j < K; j++)
				if (get_dist(nodes[i], nodes[j]) == D)
					++ans;
		cout << ans << '\n';
	}	
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) 
		solve();
}

