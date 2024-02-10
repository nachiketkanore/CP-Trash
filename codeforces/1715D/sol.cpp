/** - intuition was correct, for lexicographically min needed to see the solution
 *    Author: Nachiket Kanore
 *    Created: Saturday 10 February 2024 07:32:24 PM IST
 **/
#include "bits/stdc++.h"
#include <unistd.h>
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MAX_N = 2e5 + 5;
int N, Q;
int ans[MAX_N];
bool vis[MAX_N];
vector<array<int, 3>> comp;
array<int, 3> queries[MAX_N];
vector<pair<int, int>> adj[MAX_N];

/* void dfs(int u) {
	vis[u] = true;
	for (auto [v, w] : adj[u]) {
		if (!vis[v]) {
			comp.push_back({ u, v, w });
			dfs(v);
		}
	}
} */

/* void handle_all_ones(int bit) {
	int start = N + 1;
	for (auto [u, v, w] : comp) {
		start = min(start, u);
		start = min(start, v);
		vis[u] = vis[v] = false;
	}
	queue<int> Q;
	Q.push(start);
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		vis[curr] = true;

		for (auto [v, w] : adj[curr]) {
			if (vis[v])
				continue;
			assert(w == 1);
			if ((ans[curr] >> bit & 1) == 0) {
				ans[v] |= 1 << bit;
			}
			Q.push(v);
		}
	}
}

void handle_other_case(int bit) {
	queue<int> Q;
	for (auto [u, v, w] : comp) {
		if (w == 0) {
			Q.push(u);
			Q.push(v);
		}
		vis[u] = vis[v] = false;
	}
	while (!Q.empty()) {
		int curr = Q.front();
		Q.pop();
		if (vis[curr])
			continue;
		vis[curr] = true;

		for (auto [v, w] : adj[curr]) {
			if (vis[v] || w == 0)
				continue;
			if (w == 1) {
				if ((ans[curr] >> bit & 1) == 0)
					ans[v] |= 1 << bit;

				Q.push(v);
			}
		}
	}
} */

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	set<int> ignore;
	FOR(id, 1, Q) {
		auto& [i, j, x] = queries[id];
		cin >> i >> j >> x;
		adj[i].push_back({ j, x });
		adj[j].push_back({ i, x });
		if (i == j) {
			ignore.insert(i);
		}
	}

	F0R(bit, 31) {
		FOR(i, 1, N) ans[i] |= 1 << bit;
		FOR(id, 1, Q) {
			auto& [i, j, x] = queries[id];
			int w = x >> bit & 1;
			if (w == 0) {
				if (ans[i] >> bit & 1)
					ans[i] ^= 1 << bit;
				if (ans[j] >> bit & 1)
					ans[j] ^= 1 << bit;
			}
		}
		FOR(u, 1, N) {
			int u_val = ans[u] >> bit & 1;
			if (u_val == 1) {
				// can we make this 0?
				if (ignore.count(u))
					continue;
				bool bad = false;
				for (auto [v, x] : adj[u]) {
					int v_val = ans[v] >> bit & 1;
					int w = x >> bit & 1;
					assert(w == 1);
					if (w == 1 && v_val == 0)
						bad = true;
				}
				if (!bad) {
					ans[u] ^= 1 << bit;
				}
			}
		}
	}

	FOR(i, 1, N) cout << ans[i] << " \n"[i == N];

	return 0;
}
