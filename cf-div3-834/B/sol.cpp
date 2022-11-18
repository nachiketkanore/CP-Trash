/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 November 2022 08:10:51 PM IST
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
	int M, sum;
	cin >> M >> sum;
	set<int> have;
	F0R(i, M) {
		int u;
		cin >> u;
		have.insert(u);
	}
	FOR(val, 1, 1000) {
		if (sum - val < 0)
			break;
		if (!have.count(val) && sum - val >= 0) {
			sum -= val;
			have.insert(val);
		}
		if (sum == 0 && sz(have) == *have.rbegin()) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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
