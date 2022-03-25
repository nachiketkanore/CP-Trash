/**
 *    Author: Nachiket Kanore
 *    Created: Friday 25 March 2022 07:24:33 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	const int MOD = 998244353;
	int N;
	cin >> N;
	vector<int> dp(10, 1);
	dp[0] = 0;
	for (int i = 2; i <= N; i++) {
		vector<int> ndp(10, 0);
		FOR(curr, 1, 9) {
			FOR(prev, curr - 1, curr + 1) {
				if (prev >= 1 && prev <= 9) {
					ndp[curr] += dp[prev];
					if (ndp[curr] >= MOD) {
						ndp[curr] -= MOD;
					}
				}
			}
		}
		dp = ndp;
	}
	int ans = 0;
	F0R(i, 10) {
		ans += dp[i];
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	cout << ans << '\n';
	return 0;
}
