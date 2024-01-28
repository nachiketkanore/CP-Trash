/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 08:46:00 PM IST
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

void solve() {
	int N;
	cin >> N;
	int A[N], dp[N];
	F0R(j, N) {
		dp[j] = 1;
		cin >> A[j];
		FOR(i, max(0, j - 512), j - 1) if ((A[i] ^ j) < (A[j] ^ i)) dp[j] = max(dp[j], dp[i] + 1);
	}
	cout << *max_element(dp, dp + N) << '\n';
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
