/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 13 October 2022 08:08:54 PM IST
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

void solve() {
	int N;
	cin >> N;
	vector<int> ind[1001];
	FOR(i, 1, N) {
		int u;
		cin >> u;
		ind[u].push_back(i);
	}
	FOR(i, 1, 1000) {
		sort(ALL(ind[i]));
	}
	int ans = -1;
	FOR(i, 1, 1000) {
		FOR(j, 1, 1000) {
			if (__gcd(i, j) == 1) {
				if (sz(ind[i]) && sz(ind[j]))
					ans = max(ans, ind[i].back() + ind[j].back());
			}
		}
	}
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
