#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cassert>
#include <array>
#include <cstring>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e6 + 5, LOG = 22;

int n, val[N], ans, to;
vector<int> g[N];
bool prime[N + 2];

struct DSU {
	int n;
	vector<int> par, sizes;

	void init(int n_) {
		n = n_;
		par = vector<int> (n + 2);
		sizes = vector<int> (n + 2);

		FOR (i,1,n) {
			par[i] = i;
			sizes[i] = 1;
		}
	}

	int find(int u) {
		if (u == par[u])
			return u;
		return u = find(par[u]);
	}

	bool unite(int u, int v) {
		u = find(u), v = find(v);
		assert(u != v);
		if (sizes[u] > sizes[v]) {
			sizes[u] += sizes[v];
			sizes[v] = 0;
			par[v] = u;
		} else {
			sizes[v] += sizes[u];
			sizes[u] = 0;
			par[u] = v;
		}

		return u != v;
	}

	bool same(int u, int v) {
		return find(u) == find(v);
	}

} dsu;

void dfs(int u, int par, int curr) {
	if (u == to) {
		ans = curr;
		return;
	}

	for (int v : g[u]) if (v != par) dfs(v, u, curr + val[v]);
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);

	fill(prime + 2, prime + N, true);
	FOR (i,2,N) if (prime[i]) for (int j = 2 * i; j <= N; j += i) prime[j] = false;
	
	cin >> n;
	assert(1 <= n && n <= 1000000);
	dsu.init(n);

	FOR (i,1,n) {
		cin >> val[i];
		assert(1 <= val[i] && val[i] <= 1000000);
		val[i] = (int)prime[val[i]];
	}

	int Q;
	cin >> Q;
	assert(1 <= Q && Q <= 1000000);

	FOR (i,1,Q) {
		char type;
		cin >> type;
		int u, v;
		cin >> u >> v;

		assert(1 <= u && u <= n);
		assert(1 <= v && v <= n);

		if (type == 'A') {
			g[u].push_back(v);
			g[v].push_back(u);
			dsu.unite(u, v);
		} else if (type == 'B') {
			if (!dsu.same(u, v)) cout << "-1\n";
			else {
				ans = -1;
				to = v;
				dfs(u, u, val[u]);
				assert(~ans);
				cout << ans << "\n";
			}
		} else 
			assert(false);
	}
}