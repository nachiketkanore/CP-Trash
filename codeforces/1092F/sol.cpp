/**
 *    Author: Nachiket Kanore
 *    Created: Friday 09 February 2024 11:46:07 PM IST
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

const int MAX = 2e5 + 5;
int N, A[MAX], subtree_sum[MAX];
vector<int> adj[MAX];
int dp_down[MAX], dp_up[MAX];

void subtree_sums(int u = 1, int par = 1) {
	subtree_sum[u] = A[u];
	for (int v : adj[u]) {
		if (v ^ par) {
			subtree_sums(v, u);
			subtree_sum[u] += subtree_sum[v];
		}
	}
}

void dfs_down(int u = 1, int par = 1) {
	dp_down[u] = subtree_sum[u];
	for (int v : adj[u]) {
		if (v ^ par) {
			dfs_down(v, u);
			dp_down[u] += dp_down[v];
		}
	}
}

void dfs_up(int u = 1, int par = 1) {
	/* for (int v : adj[u]) {
		if (v ^ par) {
			int ans_up = A[u] + dp_up[u];
			for (int sib : adj[u]) {
				if (sib != par && sib != v) {
					ans_up += dp_down[sib];
					ans_up += 2 * subtree_sum[sib];
					ans_up += 2 * A[sib];
				}
			}
			ans_up += ((subtree_sum[1] + A[1]) - (subtree_sum[u] + A[u]));
			dp_up[v] = ans_up;
			dfs_up(v, u);
		}
	} */

	vector<int> sibling_contribution;
	int total = 0;
	for (int v : adj[u]) {
		if (v ^ par) {
			int contrib = 0;
			contrib += dp_down[v];
			contrib += 2 * subtree_sum[v];
			contrib += 2 * A[v];
			sibling_contribution.push_back(contrib);
			total += contrib;
		}
	}

	int idx = 0;
	for (int v : adj[u]) {
		if (v ^ par) {
			int ans_up = A[u] + dp_up[u];
			ans_up += (total - sibling_contribution[idx++]);
			// for (int sib : adj[u]) {
			// 	if (sib != par && sib != v) {
			// 		ans_up += dp_down[sib];
			// 		ans_up += 2 * subtree_sum[sib];
			// 		ans_up += 2 * A[sib];
			// 	}
			// }
			ans_up += ((subtree_sum[1] + A[1]) - (subtree_sum[u] + A[u]));
			dp_up[v] = ans_up;
			dfs_up(v, u);
		}
	}
}

int go(int u, int par, int dep = 0) {
	int ans = dep * A[u];
	for (int v : adj[u])
		if (par ^ v)
			ans += go(v, u, dep + 1);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	FOR(i, 1, N) cin >> A[i];
	F0R(i, N - 1) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	subtree_sums();
	FOR(i, 1, N) subtree_sum[i] -= A[i];
	dfs_down();
	dfs_up();

	int answer = 0;
	FOR(i, 1, N) {
		int my = dp_up[i] + dp_down[i];
		answer = max(answer, my);
		// int brute = go(i, i);
		// see(i, brute, my);
	}
	cout << answer << '\n';

	return 0;
}
