#include <bits/stdc++.h>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifndef DEBUG
#define see(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define see(...)
#endif

struct ${ $() { ios::sync_with_stdio(0); cin.tie(0); } } $;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n+1);
	vector<int> b(n+1);
	vector<pair<int,int>> edges;
	F0R (i,n-1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	FOR (i,1,n) cin >> b[i];

	int timer = 0;
	vector<int> tin(n+1), tout(n+1);
	vector<int> pref(n+1), suff(n+1);
	vector<int> subtree_max(n+1);

	function<void(int,int)> dfs = [&](int u, int par) {
		tin[u] = ++timer;
		pref[timer] = suff[timer] = b[u];
		subtree_max[u] = b[u];
		for (int v: g[u]) if (v^par) {
			edges.push_back(make_pair(u, v));
			dfs(v, u);
			cmax(subtree_max[u], subtree_max[v]);
		} 
		tout[u] = timer;
	};

	dfs(1, 1);
	FOR (i,2,n) cmax(pref[i], pref[i-1]);
	for (int i = n-1; i >= 1; i--) cmax(suff[i], suff[i+1]);

	assert(sz(edges) == n-1);

	int ans = 0;
	const int MOD = 1e9 + 7;

	auto power = [&](int a, int b) {
		int ret = 1;
		a %= MOD;
		while (b) {
			if (b & 1) ret = ret * a % MOD;
			a = a * a % MOD;
			b >>= 1;
		}
		return ret;
	};

	for (auto [u, v]: edges) {
		int L = tin[v], R = tout[v];
		int f1 = pref[L - 1];
		if (R + 1 <= n) cmax(f1, suff[R + 1]);
		int f2 = subtree_max[v];
		ans += abs(f1 - f2);
		ans %= MOD;
	}
	ans = ans * power(n - 1, MOD - 2) % MOD;
	cout << ans << '\n';
}

int32_t main() {
	int T;
	cin >> T;
	while (T--) solve();
}

