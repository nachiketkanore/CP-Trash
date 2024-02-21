/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 18 February 2024 07:08:02 PM IST
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
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	FOR(n, 1, 10000) {
		int ans = 0;
		F0R(i, n) {
			string a = to_string(i);
			string b = to_string(i + 1);
			while (sz(a) < sz(b))
				a = "0" + a;
			F0R(j, sz(b)) ans += a[j] != b[j];
		}

		int diff = ans - n;
		see(n, ans, n / 9, n + n / 9);
	}

	// int T;
	// cin >> T;
	// while (T--) {
	// 	solve();
	// }

	return 0;
}
