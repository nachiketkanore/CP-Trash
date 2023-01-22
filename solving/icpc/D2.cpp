#include <bits/stdc++.h>

#define int int64_t
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

const int inf = 1e18;
const int N = 5e5 + 5;

struct DSU {
	int n, cc;
	vector<int> par, rank;

	DSU(int n) : n(n) {
		par = vector<int>(n + 1);
		rank = vector<int>(n + 1);
		FOR(i, 1, n) {
			par[i] = i;
			rank[i] = 1;
		}
	}

	int find(int u) {
		if (u == par[u])
			return u;
		return par[u] = find(par[u]);
	}

	bool unite(int u, int v) {
		u = find(u), v = find(v);
		if (u == v)
			return false;
		if (rank[u] < rank[v])
			swap(u, v);
		par[v] = u;
		rank[u] += rank[v];
		rank[v] = 0;
		return true;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<pair<int, int>> cost(n);
	FOR(i, 1, n) cin >> a[i];
	F0R(i, n) {
		cin >> cost[i].first;
		cost[i].second = i + 1;
	}

	vector<array<int, 3>> edges;
	sort(ALL(cost));

	DSU comps(n);
	FOR(i, 1, n) comps.unite(i, a[i]);
	DSU mst(n);

	for (int i = 1; i < n; i++) {
		int u = cost[i].second;
		u = comps.find(u);
		int v = cost[i - 1].second;
		v = comps.find(v);
		if (comps.find(u) != comps.find(v)) {
			edges.push_back({ abs(cost[i].first - cost[i - 1].first), u, v });
		}
	}

	sort(ALL(edges));
	int ans = 0;
	for (auto [w, u, v] : edges)
		if (mst.unite(u, v))
			ans += w;
	cout << ans << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	while (T--)
		solve();
}
