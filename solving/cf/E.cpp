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

int n, C, c[N], ans[N];
vector<int> g[N];
vector<int> curr[N];

void dfs(int u) {
	ans[u] = (sz(curr[c[u]]) ? curr[c[u]].back() : -1);
	curr[c[u]].push_back(u);
	for (int v : g[u])
		dfs(v);
	curr[c[u]].pop_back();
}

int32_t main() {
	cin >> n >> C;
	FOR(i, 2, n) {
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	FOR(i, 1, n) cin >> c[i];
	dfs(1);
	FOR(i, 1, n) cout << ans[i] << " \n"[i == n];
}
