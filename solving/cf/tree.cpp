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
const int N = 2e5 + 5;

int n, ans, keep[N];
bool vis[N];
vector<int> g[N];

int32_t main() {
	cin >> n;
	FOR (i,1,n) keep[i] = -1;
	F0R (i,n-1) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		cmax(ans, sz(g[u]));
		cmax(ans, sz(g[v]));
	}
	
	queue<int> Q;
	keep[1] = 0;
	vis[1] = true;

	Q.push(1);
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();

		for (int nxt: g[curr]) {
			if (vis[nxt]) continue;
		} 
	}

}

