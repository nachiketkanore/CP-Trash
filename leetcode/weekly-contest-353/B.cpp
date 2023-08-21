#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int maximumJumps(vector<int>& A, int T) {
		const int N = A.size();
		vector<int> dp(N, -1e6);
		dp[0] = 0;
		for (int j = 0; j < N; j++) {
			for (int i = j - 1; ~i; i--) {
				if (-T <= A[j] - A[i] && A[j] - A[i] <= T) {
					dp[j] = max(dp[j], dp[i] + 1);
				}
			}
		}
		return dp.back() < 0 ? -1 : dp.back();
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solution S;
	vector<int> A = { 1, 3, 6, 4, 1, 2 };
	cout << S.maximumJumps(A, 2) << '\n';
	return 0;
}
