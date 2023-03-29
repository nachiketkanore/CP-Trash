/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 29 March 2023 11:21:20 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int _ = 15, MOD = 1e9 + 7;
int n, T, t[_], g[_], dp[3][226][1 << _];

int go(int mask, int rem, int prev_g) {
	if (rem <= 0)
		return rem == 0;
	int& ans = dp[prev_g][rem][mask];
	if (~ans)
		return ans;
	ans = 0;

	for (int nxt = 0; nxt < n; nxt++) {
		if ((mask >> nxt & 1) == 0) {
			if (prev_g ^ g[nxt]) {
				ans += go(mask | (1 << nxt), rem - t[nxt], g[nxt]);
				if (ans >= MOD)
					ans -= MOD;
			}
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	cin >> n >> T;
	F0R(i, n) cin >> t[i] >> g[i], g[i]--;

	int ans = 0;
	F0R(i, n) {
		ans += go(1 << i, T - t[i], g[i]);
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans << '\n';

	return 0;
}
