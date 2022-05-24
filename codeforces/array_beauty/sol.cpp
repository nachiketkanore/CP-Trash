/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 25 May 2022 12:36:14 AM IST
 **/
#include "bits/stdc++.h"

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int MOD = 998244353;
const int _ = 1010;
int N, K, A[_], x, dp[_][_];

int go(int id, int rem) {
	if (rem == 0) {
		return 1;
	}
	if (id == N)
		return 0;

	int& ans = dp[id][rem];
	if (~ans)
		return ans;
	ans = 0;

	int next_id = lower_bound(A + id + 1, A + N, A[id] + x) - A;
	if (next_id == N)
		next_id = -1;

	int c1 = go(id + 1, rem);
	int c2 = 0;
	if (~next_id) {
		c2 = go(next_id, rem - 1);
	} else if (rem == 1) {
		c2 = 1;
	}

	ans = c1 + c2;
	if (ans >= MOD)
		ans -= MOD;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	F0R(i, N) cin >> A[i];

	sort(A, A + N);
	const int MAX = A[N - 1] - A[0];

	int answer = 0;
	FOR(x, 1, MAX / (K - 1)) {
		F0R(i, N) F0R(j, K + 1) dp[i][j] = -1;
		::x = x;
		int cnt = go(0, K);
		answer += cnt;
		if (answer >= MOD) {
			answer -= MOD;
		}
	}

	cout << answer << '\n';

	return 0;
}
