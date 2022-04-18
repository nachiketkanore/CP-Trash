/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 02:55:19 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N;
	cin >> N;
	int tot = 0, A[N];
	F0R(i, N) {
		cin >> A[i];
		tot += A[i];
	}
	if (tot & 1) {
		cout << "NO\n";
	} else {
		const int want = tot >> 1;
		bool dp[want + 1];
		memset(dp, false, sizeof(dp));
		dp[0] = true;
		F0R(i, N) {
			bool ndp[want + 1];
			memset(ndp, false, sizeof(ndp));
			FOR(val, 1, want) {
				ndp[val] |= dp[val];
				if (val - A[i] >= 0)
					ndp[val] |= dp[val - A[i]];
			}
			F0R(i, want + 1) dp[i] = ndp[i];
		}
		cout << (dp[want] ? "YES\n" : "NO\n");
	}
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
