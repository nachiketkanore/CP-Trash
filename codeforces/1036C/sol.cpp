/**
 *    Author: Nachiket Kanore
 *    Created: Friday 02 June 2023 05:13:02 PM IST
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

string S;
int dp[20][2][4];

int go(int id, bool small_taken, int non_zero_digits) {
	if (non_zero_digits > 3)
		return 0;
	if (id == S.size())
		return 1;

	int& ans = dp[id][small_taken][non_zero_digits];
	if (~ans)
		return ans;
	ans = 0;

	int lo = 0, hi = (small_taken ? 9 : S[id] - '0');
	FOR(digit, lo, hi) {
		ans += go(id + 1, small_taken || (digit < S[id] - '0'), non_zero_digits + (digit != 0));
	}
	return ans;
}

int solve(int N) {
	::S = to_string(N);
	memset(dp, -1, sizeof(dp));
	return go(0, false, 0);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int L, R;
		cin >> L >> R;
		cout << solve(R) - solve(L - 1) << '\n';
	}

	return 0;
}
