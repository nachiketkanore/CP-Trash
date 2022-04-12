/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 12 April 2022 11:09:47 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, K;
	cin >> N >> K;
	if (N == 1) {
		cout << "0\n";
		return;
	}
	vector<set<int>> g(N);
	F0R(i, N - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].insert(v);
		g[v].insert(u);
	}
	vector<int> leaves;
	set<int> remain;
	F0R(i, N) {
		remain.insert(i);
		if (sz(g[i]) == 1) {
			leaves.push_back(i);
		}
	}
	while (sz(leaves) && K-- > 0) {
		vector<int> nleaves;
		for (int u : leaves) {
			int who = -1;
			remain.erase(u);
			for (int v : g[u]) {
				g[v].erase(u);
				who = v;
			}
			if (~who) {
				g[u].erase(who);
				if (sz(g[who]) == 1) {
					nleaves.push_back(who);
				}
			}
		}
		leaves = nleaves;
	}
	cout << sz(remain) << '\n';
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
