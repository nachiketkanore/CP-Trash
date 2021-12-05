#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(),(x).end()
#define F0R(i,R) for(int i = (0); i < (R); ++i)
#define FOR(i,L,R) for(int i = (L); i <= (R); ++i)

using namespace std;

template<class T> bool cmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool cmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 


const int _ = 1e5 + 5;
vector<int> G[_];
int N, val[_], pref[_], suff[_];
int tin[_], tout[_], timer = 0;
int euler[_];

void dfs(int u = 1, int par = 1) {
	tin[u] = ++timer;
	euler[timer] = u;
	for (int v: G[u]) {
		if (v != par) {
			dfs(v, u);
		}
	}
	tout[u] = timer;
}

int32_t main() {
	cin >> N;
	F0R (i,N-1) {
		int u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	FOR (i,1,N) {
		cin >> val[i];
	}
	dfs();
	assert(N == timer);
	FOR (i,1,N) {
		pref[i] = val[euler[i]];
		suff[i] = val[euler[i]];
	}
	FOR (i,1,N) {
		pref[i] = __gcd(pref[i], pref[i-1]);
	}
	for (int i = N-1; i >= 1; i--) {
		suff[i] = __gcd(suff[i], suff[i+1]);
	}
	int ans = pref[N];
	FOR (i,1,N) {
		int L = tin[i], R = tout[i];
		cmax(ans, __gcd(pref[L-1], suff[R+1]));
	}
	cout << ans;
}
