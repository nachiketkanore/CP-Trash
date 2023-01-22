#include <bits/stdc++.h>

#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

struct $ {
	$() {
		ios::sync_with_stdio(0);
		cin.tie(0);
	}
} $;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e9;

// source: https://cp-algorithms.com/graph/lca_binary_lifting.html
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout, height;
vector<vector<int>> up;

void dfs(int v, int p, int dist = 1) {
	tin[v] = ++timer;
	height[v] = dist;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];

	for (int u : adj[v]) {
		if (u != p)
			dfs(u, v, dist + 1);
	}

	tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
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
	cin >> n;
	adj = vector<vector<int>>(n);
	F0R(i, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	preprocess(0);

	auto get_LCA = [&](unordered_set<int>& take) {
		vector<int> nodes(ALL(take));
		assert(sz(nodes));
		sort(ALL(nodes), [&](int u, int v) { return tin[u] < tin[v]; });
		int ret = nodes.front();
		for (int i = 1; i < sz(nodes); i++) {
			ret = lca(ret, nodes[i]);
		}
		return ret;
	};

	auto get_bottom = [&](unordered_set<int>& nodes) {
		assert(sz(nodes));
		int ret = -1, best = -inf;
		for (int x : nodes) {
			if (best < height[x]) {
				ret = x;
				best = height[x];
			}
		}
		assert(~ret);
		return ret;
	};

	auto on_path = [&](int u, int v, int who) {
		// u is in subtree of v
		return is_ancestor(who, u) && is_ancestor(v, who);
	};

	int Q;
	cin >> Q;
	while (Q--) {
		int k;
		cin >> k;
		unordered_set<int> nodes;
		F0R(j, k) {
			int u;
			cin >> u;
			--u;
			nodes.insert(u);
		}

		int root = get_LCA(nodes);
		int low = get_bottom(nodes);

		// removing all nodes on path: low --> root
		{
			vector<int> remove;
			for (int x : nodes)
				if (on_path(low, root, x))
					remove.push_back(x);
			for (int rem : remove) {
				nodes.erase(rem);
			}
		}
		if (!sz(nodes)) {
			cout << "YES\n";
			continue;
		}

		int low2 = -1;
		{
			int best = -1;
			for (int x : nodes) {
				if (lca(x, low) == root) {
					if (best < height[x]) {
						best = height[x];
						low2 = x;
					}
				}
			}
		}
		bool bad = low2 == -1;
		if (bad) {
			cout << "NO\n";
			continue;
		}
		// removing all nodes on path: low2 --> root
		{
			vector<int> remove;
			for (int x : nodes)
				if (on_path(low2, root, x))
					remove.push_back(x);
			for (int rem : remove) {
				nodes.erase(rem);
			}
		}
		if (sz(nodes) || bad)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}

int32_t main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
