/**
 *    Author: Nachiket Kanore
 *    Created: Friday 22 July 2022 11:38:25 PM IST
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

const int MOD = 1e9 + 7;
const int _ = 1e2;
const int OFF = 20000;
int N, M, A[_], B[_], dp1[2][_][OFF << 1], dp2[2][_][OFF << 1];

int power(int a, int b, int mod = MOD) {
	int ret = 1;
	a %= mod;
	while (b > 0) {
		if (b % 2)
			ret = ret * a % mod;
		b /= 2;
		a = a * a % mod;
	}
	return ret;
}

int go2(int id, int rem, bool taken) {
	if (rem < -10000)
		return 0;
	if (id == M)
		return rem == 0 && taken;
	int& ans = dp2[taken][id][rem + OFF];
	if (~ans)
		return ans;
	ans = 0;
	ans += go2(id + 1, rem, taken);
	ans += go2(id + 1, rem - B[id], true);
	return ans;
}

int go1(int id, int rem, bool taken) {
	if (rem < -10000)
		return 0;
	if (id == N)
		return rem == 0 && taken;
	int& ans = dp1[taken][id][rem + OFF];
	if (~ans)
		return ans;
	ans = 0;
	ans += go1(id + 1, rem, taken);
	ans += go1(id + 1, rem - A[id], true);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	cin >> N >> M;

	F0R(i, N) cin >> A[i];
	F0R(j, M) cin >> B[j];

	int ways = 0;
	int total_ways = (power(2, N) - 1) * (power(2, M) - 1) % MOD;

	FOR(sum, -10000, 10000) {
		int pairs = go1(0, sum, false) * go2(0, sum, false) % MOD;
		ways = (ways + pairs) % MOD;
	}

	int ans = ways * power(total_ways, MOD - 2, MOD) % MOD;
	cout << ans << '\n';

	return 0;
}
