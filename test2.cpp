#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, W; // number of items and knapsack capacity
	cin >> N >> W;
	int value[N], weight[N]; // values and weights of items
	for (int i = 0; i < N; i++) {
		cin >> value[i] >> weight[i];
	}
	vector<int> dp(W + 1);

	for (int i = 0; i < N; i++) {
		vector<int> new_dp(W + 1);
		for (int w = 0; w <= W; w++) {
			if (i - 1 >= 0)
				new_dp[w] = max(new_dp[w], dp[w]);
			if (w - weight[i] >= 0 && i - 1 >= 0)
				new_dp[w] = max(new_dp[w], value[i] + dp[w - weight[i]]);
		}
		dp = new_dp;
	}

	int best = 0;
	for (int w = 0; w <= W; w++) {
		best = max(best, dp[w]);
	}
	cout << best;
	return 0;
}
