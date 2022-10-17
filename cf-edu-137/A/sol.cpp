/**
 *    Author: Nachiket Kanore
 *    Created: Monday 17 October 2022 08:05:51 PM IST
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
	bool bad[10] = { false };
	F0R(i, N) {
		int d;
		cin >> d;
		bad[d] = true;
	}
	int ans = 0;
	F0R(a, 10) for (int b = a + 1; b < 10; b++) {
		if (bad[a] || bad[b])
			continue;
		// see(a, b);
		ans += 6;
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
