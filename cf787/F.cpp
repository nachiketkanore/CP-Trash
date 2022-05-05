/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 05 May 2022 08:35:35 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 2e5 + 5, LG = 20;

int tim = 0;
int parent[LG][_];
int tin[_], tout[_], level[_];
std::vector<int> g[_];
int n;

void dfs(int k, int par, int lvl) {
	tin[k] = ++tim;
	parent[0][k] = par;
	level[k] = lvl;
	for (auto it : g[k]) {
		if (it == par)
			continue;
		dfs(it, k, lvl + 1);
	}
	tout[k] = tim;
}

void precompute() {
	for (int i = 1; i < LG; i++)
		for (int j = 1; j <= n; j++)
			if (parent[i - 1][j])
				parent[i][j] = parent[i - 1][parent[i - 1][j]];
}

int LCA(int u, int v) {
	if (level[u] < level[v])
		swap(u, v);
	int diff = level[u] - level[v];
	for (int i = LG - 1; i >= 0; i--) {
		if ((1 << i) & diff) {
			u = parent[i][u];
		}
	}
	if (u == v)
		return u;
	for (int i = LG - 1; i >= 0; i--) {
		if (parent[i][u] && parent[i][u] != parent[i][v]) {
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}

int dist(int u, int v) {
	return level[u] + level[v] - 2 * level[LCA(u, v)];
}

template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
	os << '{';
	string sep;
	for (const auto& x : v)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename T, size_t size>
ostream& operator<<(ostream& os, const array<T, size>& arr) {
	os << '{';
	string sep;
	for (const auto& x : arr)
		os << sep << x, sep = ", ";
	return os << '}';
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
	return os << '(' << p.first << ", " << p.second << ')';
}

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}

#ifdef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int k;
		cin >> n >> k;
		int x, y;
		cin >> x >> y;
		set<int> path_;
		F0R(i, k) {
			int u;
			cin >> u;
			if (u == x)
				continue;
			path_.insert(u);
		}
		path_.insert(y);
		FOR(i, 0, n) {
			g[i].clear();
			tin[i] = tout[i] = level[i] = 0;
			F0R(j, LG) parent[j][i] = 0;
			tim = 0;
		}
		F0R(i, n - 1) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		FOR(i, 1, n) {
			vector<int> adj;
			bool has = false;
			for (int v : g[i]) {
				if (v == y) {
					has = true;
				} else {
					adj.push_back(v);
				}
			}
			if (has)
				adj.push_back(y);
			g[i] = adj;
		}
		vector<int> path(ALL(path_));
		dfs(x, x, 1);
		precompute();
		sort(ALL(path), [&](int one, int two) { return tin[one] < tin[two]; });
		int ans = 0;
		int curr = x;
		for (int node : path) {
			ans += dist(curr, node);
			curr = node;
		}
		ans += dist(curr, x);
		ans -= dist(x, y);
		cout << ans << '\n';
	}
	return 0;
}
