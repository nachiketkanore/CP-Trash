/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 26 October 2023 12:21:13 PM IST
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

const int MAX = 1e5 + 10;
int N, K, A[MAX], subtree_sum[MAX], dp_down[MAX], dp_up[MAX];
vector<int> adj[MAX];

void dfs(int u, int par) {

	subtree_sum[u] = A[u];

	for (int v : adj[u]) {
		if (v != par) {
			dfs(v, u);
			subtree_sum[u] += subtree_sum[v];
		}
	}
}

void dfs_down(int u, int par) {

	for (int v : adj[u]) {
		if (v != par) {
			dfs_down(v, u);
			dp_down[u] += dp_down[v];
		}
	}

	dp_down[u] += subtree_sum[u] - A[u];
}

void dfs_up(int u, int par) {

	int total_contribution = 0;

	for (int c : adj[u]) {
		if (c != par) {
			total_contribution += dp_down[c] + 2 * subtree_sum[c];
		}
	}

	for (int c : adj[u]) {
		if (c != par) {

			dp_up[c] += dp_up[u];
			dp_up[c] += A[u];
			dp_up[c] += (subtree_sum[1] - subtree_sum[u]);

			/* for (int sibling : adj[u]) {
				if (sibling != par && sibling != c) {
					dp_up[c] += dp_down[sibling] + 2 * subtree_sum[sibling];
				}
			} */
			int self_contribution = dp_down[c] + 2 * subtree_sum[c];
			int sibling_contribution = total_contribution - self_contribution;
			dp_up[c] += sibling_contribution;

			dfs_up(c, u);
		}
	}
}

void solve() {
	cin >> N >> K;
	FOR(i, 1, N) {
		cin >> A[i];
		adj[i].clear();
		subtree_sum[i] = dp_up[i] = dp_down[i] = 0;
	}
	F0R(i, N - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 1);
	dfs_down(1, 1);
	dfs_up(1, 1);

	vector<int> rating_values;
	FOR(r, 1, N) {
		int rating = dp_up[r] + dp_down[r];
		rating_values.push_back(rating);
		// see(r, rating);
	}
	sort(ALL(rating_values));
	cout << rating_values[K - 1] << '\n';
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
