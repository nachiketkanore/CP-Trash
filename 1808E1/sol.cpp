/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 30 March 2023 03:28:41 PM IST
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

int MOD;
int n, k;
bool vis[2][30][100][2901];
int dp[2][30][100][2901];

int go(int id, int rem_sum, bool found, int sum) {
	if (found && rem_sum == 0)
		return 1;
	if (rem_sum < 0)
		return 0;
	if (id == n)
		return found && rem_sum == 0;

	if (vis[found][sum][id][rem_sum])
		return dp[found][sum][id][rem_sum];

	vis[found][sum][id][rem_sum] = true;
	int& ans = dp[found][sum][id][rem_sum];
	ans = 0;

	F0R(put, k) {
		bool nfound = found || (2 * put) % k == sum;
		ans += go(id + 1, rem_sum - put, nfound, sum);
		if (ans >= MOD)
			ans -= MOD;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> MOD;

	int max_sum = (k - 1) * n;
	int ans = 0;
	F0R(sum, max_sum + 1) {
		ans += go(0, sum, false, sum % k);
		if (ans >= MOD)
			ans -= MOD;
	}
	cout << ans;

	return 0;
}
