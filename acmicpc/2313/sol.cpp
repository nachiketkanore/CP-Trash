/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 23 August 2023 11:35:54 PM IST
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

const int INF = 1e18;

int solve() {
	int N;
	cin >> N;
	int best = -INF;
	int sum = 0, pref = INF;
	F0R(i, N) {
		int u;
		cin >> u;
		sum += u;
		best = max(best, sum);
		best = max(best, sum - pref);
		pref = min(pref, sum);
	}
	return best;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, ans = 0;
	cin >> T;

	while (T--) {
		ans += solve();
	}
	cout << ans << '\n';

	return 0;
}
