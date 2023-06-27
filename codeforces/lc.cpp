#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	int idealArrays(int N, int MX) {
		// dp[i][put_here] = sum over dp[i - 1][prev_value], prev_value in [1, max]
		// fi put_here % prev_value == 0
		// O (N * MX * MX)
		const int MOD = 1e9 + 7;
		vector<int> dp(MX + 1, 1);

		for (int i = 1; i < N; i++) {
			vector<int> ndp(MX + 1);
			for (int put = 1; put <= MX; put++) {
				// for (int prev: divisor_of(put)) { // O(sqrt(MX))
				// notice: prev is divisor of put
				if (put % prev == 0) {
					ndp[put] += dp[prev];
					if (ndp[put] >= MOD) {
						ndp[put] -= MOD;
					}
				}
			}
		}
		dp = ndp;
	}

	for (int i = 1; i <= MX; i++) {
		ans += dp[i];
		if (ans >= MOD)
			ans -= MOD;
	}
	return ans;
}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}

