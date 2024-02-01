/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 01 February 2024 06:36:51 PM IST
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

const int MAX = 16;
int N, D, W[MAX];
long double x_bar, dp[1 << MAX][MAX], mask_sum[1 << MAX];
bool vis[1 << MAX][MAX];
const long double INF = 1e18;

long double go(int mask, int bags) {
	if (bags < 0)
		return INF;
	if (bags == 1) {
		return pow(mask_sum[mask] - x_bar, 2);
	}
	if (mask == 0)
		return 0;

	if (vis[mask][bags])
		return dp[mask][bags];
	vis[mask][bags] = true;

	long double ans = pow(mask_sum[mask] - x_bar, 2);
	for (int sub_mask = mask; sub_mask; sub_mask = (sub_mask - 1) & mask) {
		// long double cost = pow(mask_sum[sub_mask] - x_bar, 2);
		long double cost = go(sub_mask, 1) + go(mask - sub_mask, bags - 1);
		ans = min(ans, cost);
	}

	dp[mask][bags] = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> D;
	F0R(i, N) {
		cin >> W[i];
		x_bar += W[i];
	}
	F0R(mask, 1 << N) F0R(i, N) if (mask >> i & 1) mask_sum[mask] += W[i];
	x_bar = 1.0 * x_bar / D;

	long double answer = 1. * go((1 << N) - 1, D) / D;
	cout << setprecision(10) << answer;

	return 0;
}
