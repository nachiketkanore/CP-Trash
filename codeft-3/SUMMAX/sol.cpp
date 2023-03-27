/**
 *    Author: Nachiket Kanore
 *    Created: Monday 27 March 2023 08:17:19 PM IST
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
	int a[4];
	int ans = 0;
	F0R(i, 4) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		ans = max(ans, a[i]);
		for (int j = i + 2; j < 4; j++) {
			ans = max(ans, a[i] + a[j]);
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
