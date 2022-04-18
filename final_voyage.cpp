/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 03:04:49 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, W;
	cin >> N >> W;
	int weight[N], value[N];
	F0R(i, N) cin >> weight[i];
	F0R(i, N) cin >> value[i];
	int dp[W + 1];
	F0R(i, W + 1) {
		dp[i] = 0;
	}
	F0R(i, N) {
		int ndp[W + 1];
		F0R(j, W + 1) ndp[j] = 0;
		F0R(j, W + 1) {
			ndp[j] = max(ndp[j], dp[j]);
			if (j - weight[i] >= 0)
				ndp[j] = max(ndp[j], value[i] + dp[j - weight[i]]);
		}
		F0R(j, W + 1) dp[j] = ndp[j];
	}
	int ans			  = 0;
	F0R(i, W + 1) ans = max(ans, dp[i]);
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
