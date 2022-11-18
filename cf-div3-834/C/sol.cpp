/**
 *    Author: Nachiket Kanore
 *    Created: Friday 18 November 2022 08:46:14 PM IST
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
	int L, R, X, a, b;
	cin >> L >> R >> X >> a >> b;

	const int INF = 1e9;

	function<int(int, int)> go = [&](int curr, int steps) {
		if (curr == b)
			return steps;
		if (steps > 3)
			return INF;
		int ans = INF;
		int gl = curr - X, gr = curr + X;
		if (gl >= L) {
			ans = min(ans, go(L, steps + 1));
			if (b <= gl)
				ans = min(ans, go(b, steps + 1));
		}
		if (gr <= R) {
			ans = min(ans, go(R, steps + 1));
			if (b >= gr)
				ans = min(ans, go(b, steps + 1));
		}
		return ans;
	};

	int ans = go(a, 0);
	if (ans >= INF)
		ans = -1;
	cout << ans << '\n';
	return;
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
