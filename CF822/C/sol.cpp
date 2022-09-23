/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 September 2022 06:10:25 PM IST
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
	vector<bool> keep(N + 1), have(N + 1, true);
	FOR (i,1,N) {
		char status;
		cin >> status;
		keep[i] = status == '1';
	}
	int ans = 0;
	FOR (k, 1, N) {
		if (keep[k]) assert(have[k]);
		int multiples = 0;
		for (int m = k; m <= N; m += k) {
			multiples += have[m];
		}
		if (multiples == 0) continue;
		// see(k, multiples);
		for (int m = k; m <= N; m += k) {
			if (keep[m]) break;
			if (have[m]) ans += k;
			have[m] = false;
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
