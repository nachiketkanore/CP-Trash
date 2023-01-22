/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 19 March 2022 12:40:55 AM IST
 **/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e6;

int dp[N], pref_dp[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[1] = pref_dp[1] = 1;
	for (int i = 2; i < N; i++) {
		int m = sqrt(i);
		dp[i] = pref_dp[m];
		pref_dp[i] = pref_dp[i - 1] + dp[i];
	}
	int T;
	cin >> T;
	while (T--) {
		int X;
		cin >> X;
		int root = sqrtl(X);
		int root4 = sqrtl(root);
		int ans = 0;
		for (int i = 1; i <= root4; i++) {
			ans += (root - i * i + 1) * dp[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
