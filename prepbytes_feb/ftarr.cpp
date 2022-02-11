/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 12 February 2022 12:05:22 AM IST
**/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	int n, k;
	cin >> n >> k;
	int ans = k;
	const int MOD = 1e9 + 7;
	for (int i = 1; i < n; i++) {
		ans = 1ll * ans * (k - 1) % MOD;
	}
	cout << ans;
	return 0;
}
