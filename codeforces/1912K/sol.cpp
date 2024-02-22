/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 06:28:07 PM IST
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

const int _ = 2e5;
const int MOD = 998244353;
int N, A[_], dp[2][2][4][_];

int go(int id, int a, int b, int len) {
	if (id == N)
		return len >= 3;
	int& ans = dp[a][b][min(int(3), len)][id];
	if (~ans)
		return ans;
	ans = 0;
	if (len < 2) {
		ans += go(id + 1, b & 1, A[id] & 1, len + 1);
		ans += go(id + 1, a, b, len);
	} else {
		if ((a + b + A[id]) % 2 == 0) {
			ans += go(id + 1, b & 1, A[id] & 1, len + 1);
		}
		ans += go(id + 1, a, b, len);
	}
	ans %= MOD;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	F0R(i, N) cin >> A[i];
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0, 0, 0);

	return 0;
}
