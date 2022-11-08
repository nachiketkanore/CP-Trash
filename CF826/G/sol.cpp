/**
 *    Author: Nachiket Kanore
 *    Created: Monday 07 November 2022 12:14:38 AM IST
 **/
#include "bits/stdc++.h"
#include <complex>
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

void solve() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N);

	F0R(i, M) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int f;
	cin >> f;
	vector<int> h(f), cars(N);
	F0R(i, f) {
		cin >> h[i], --h[i];
		cars[h[i]]++;
	}
	int k;
	cin >> k;
	vector<int> p(k);
	vector<bool> has_car(f, true);
	F0R(i, k) {
		cin >> p[i], --p[i];
		cars[h[p[i]]]--;
		has_car[h[p[i]]] = false;
	}

	vector<int> curr = { 0 };
	vector<vector<int>> masks(N);
	vector<bool> vis(N, false);
	set<int> friends(ALL(h));

	while (!curr.empty()) {
		vector<int> ncurr;
		for (int u : curr)
			vis[u] = true;
		for (int u : curr) {
			if (friends.count(u)) {
				int add = 0;
				F0R(i, k) if (h[p[i]] == u) add |= 1 << i;
				if (masks[u].empty()) {
					masks[u].push_back(add);
				} else {
					for (int& msk : masks[u])
						msk |= add;
				}
			}

			for (int v : g[u]) {
				if (!vis[v]) {
					for (int msk : masks[u]) {
						masks[v].push_back(msk);
					}
					ncurr.push_back(v);
				}
			}
		}

		curr = ncurr;
	}

	vector<vector<int>> dp(f, vector<int>(1 << 6, -1));

	function<int(int, int)> go = [&](int id, int mask) {
		if (id == f) {
			return k - __builtin_popcount(mask);
		}
		int& ans = dp[id][mask];
		if (~ans)
			return ans;
		ans = k;
		if (has_car[h[id]]) {
			for (int msk : masks[h[id]]) {
				ans = min(ans, go(id + 1, mask | msk));
			}
		} else {
			ans = min(ans, go(id + 1, mask));
		}
		return ans;
	};

	int ans = go(0, 0);
	cout << ans << '\n';
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
