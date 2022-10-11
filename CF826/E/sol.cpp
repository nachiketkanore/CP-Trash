/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 11 October 2022 10:58:10 PM IST
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
	int A[N + 1];
	FOR(i, 1, N) cin >> A[i];
	vector<int> dp(N + 2, false);
	dp[0] = true;
	FOR(i, 1, N) {
		int prev = i - A[i] - 1;
		if (prev >= 0) {
			dp[i] |= dp[prev];
		}
		int nxt = i + A[i];
		if (nxt <= N && dp[i - 1]) {
			dp[nxt] = true;
		}
	}
	cout << (dp[N] ? "YES\n" : "NO\n");
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
