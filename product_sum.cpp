/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 15 May 2022 08:50:45 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 5005;
int N, A[_], B[_], ans, pref[_], suff[_];
int dp[_][_];

int go(int L, int R) {
	if (L > R)
		return 0;
	int& ans = dp[L][R];
	if (~ans)
		return ans;
	ans = 0;
	if (L == R) {
		ans = A[L] * B[L];
	} else {
		ans = A[L] * B[R] + A[R] * B[L];
	}
	ans += go(L + 1, R - 1);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> N;
	FOR(i, 1, N) cin >> A[i];
	FOR(i, 1, N) {
		cin >> B[i];
		pref[i] = A[i] * B[i] + pref[i - 1];
	}
	for (int i = N; i >= 1; i--) {
		suff[i] = A[i] * B[i] + suff[i + 1];
	}
	FOR(i, 1, N) {
		FOR(j, i, N) {
			ans = max(ans, pref[i - 1] + go(i, j) + suff[j + 1]);
		}
	}
	cout << ans;
	return 0;
}
