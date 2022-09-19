/**
 *    Author: Nachiket Kanore
 *    Created: Monday 19 September 2022 10:24:43 PM IST
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
	int N, K; cin >> N >> K;
	vector<int> vals(K);
	F0R (i, N) {
		int u; cin >> u;
		vals[i % K] = max(vals[i % K], u);
	}
	int ans = 0;
	F0R (i,K) {
		ans += vals[i];
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
