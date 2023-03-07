/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 07 March 2023 01:43:44 PM IST
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

const int _ = 2e5 + 5;
int N, A[_], dp[_], dp_pref_max[_], ans;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	/* // O(N*N*N)
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
		for (int j = i; j >= 1; j--) {
			if (A[i] - A[j - 1] >= 0) {
				int best_pref = 0;
				FOR(k, 1, j - 1) best_pref = max(best_pref, dp[k]);
				dp[i] = max(dp[i], (i - j + 1) + best_pref);
			}
		}
		ans = max(ans, dp[i]);
	} */

	// O(N*N)
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
		for (int j = i; j >= 1; j--) {
			if (A[i] - A[j - 1] >= 0) {
				int best_pref = dp_pref_max[j - 1];
				dp[i] = max(dp[i], (i - j + 1) + best_pref);
			}
		}
		dp_pref_max[i] = max(dp_pref_max[i], dp[i]);
		ans = max(ans, dp[i]);
	}

	// Better solution?
	// TODO
	cout << ans;

	return 0;
}
