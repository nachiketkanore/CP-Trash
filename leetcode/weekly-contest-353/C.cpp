#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int maxNonDecreasingLength(vector<int>& A, vector<int>& B) {
		const int N = A.size();
		vector<vector<int>> dp(2, vector<int>(N, -1));

		function<int(int, int)> go = [&](int id, int prev) {
			if (id >= N) {
				return 0;
			}
			int& ans = dp[prev][id];
			if (~ans) {
				return ans;
			}
			ans = 0;

			int last = (prev == 0 ? A[id - 1] : B[id - 1]);

			// take A[id]
			if (last <= A[id]) {
				int c1 = 1 + go(id + 1, 0);
				ans = max(ans, c1);
			}
			// take B[id]
			if (last <= B[id]) {
				int c2 = 1 + go(id + 1, 1);
				ans = max(ans, c2);
			}

			return ans;
		};

		int ans = 1;
		for (int i = 0; i < N; i++) {
			// first element of our subarray is A[i] or B[i]
			int c1 = 1 + go(i + 1, 0);
			int c2 = 1 + go(i + 1, 1);
			ans = max(ans, c1);
			ans = max(ans, c2);
		}
		return ans;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
