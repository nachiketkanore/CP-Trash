/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 19 July 2023 09:56:46 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MAX = 1e5 + 5;
vector<int> G[MAX];
int N, M, col[MAX], flip_count[MAX];

void dfs(int u, int par) {
	for (int v : G[u]) {
		if (v ^ par) {
			dfs(v, u);
			flip_count[u] += flip_count[v];
		}
	}
}

void solve() {
	cin >> N >> M;
	F0R(i, N) {
		G[i].clear();
		flip_count[i] = 0;
	}
	F0R(i, N) cin >> col[i];
	F0R(e, N - 1) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	F0R(i, M) {
		int x;
		cin >> x;
		flip_count[x]++;
	}
	dfs(0, 0);

	int answer = 0;
	F0R(i, N) {
		answer += (col[i] ^ (flip_count[i] & 1)) == 1;
	}
	cout << answer << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}
