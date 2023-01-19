#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> str) {
	int n = str.size();
	int dp[n + 1][n + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 0;
		}
	}
	for (int len = 1; len <= n; len++) {
		for (int i = 0, j = len - 1; j < n; i++, j++) {
			if (len == 1)
				dp[i][j] = 1;
			else {
				dp[i][j] = 1 + dp[i + 1][j];
				if (str[i] == str[i + 1]) {
					dp[i][j] = min(1 + dp[i + 2][j], dp[i][j]);
				}
				for (int K = i + 2; K <= j; K++) {
					if (str[i] == str[K]) {
						dp[i][j] = min(dp[i + 1][K - 1] + dp[K + 1][j], dp[i][j]);
					}
				}
			}
		}
	}
	return dp[0][n - 1];
}
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int& x : A) {
		cin >> x;
	}
	cout << solve(A) << '\n';
	return 0;
}
