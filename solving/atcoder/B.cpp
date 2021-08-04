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

int n, a[N], par[N], Size[N];

int Find(int u) {
	if (u == par[u]) return u;
	return par[u] = Find(par[par[u]]);
}

void unite(int u, int v) {
	u = Find(u), v = Find(v);
	if (u == v) return;
	if (Size[u] > Size[v]) swap(u, v);
	par[u] = v;
	Size[v] += Size[u];
	Size[u] = 0;
}

int32_t main() {
	cin >> n;
	int mx = -1;
	FOR (i,1,n) cin >> a[i], cmax(mx, a[i]);

	FOR (i,1,mx) par[i] = i, Size[i] = 1;

	int L = 1, R = n;
	while (L < R) {
		unite(a[L++], a[R--]);
	}

	int ans = 0;
	FOR (i,1,mx) if (Find(i) == i) ans += Size[i] - 1;
	
	cout << ans << '\n';
}

