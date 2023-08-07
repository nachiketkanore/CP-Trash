#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	static bool canSplitArray(vector<int> A, int M) {
		const int N = A.size();
		for (int i = 1; i < N; i++) {
			A[i] += A[i - 1];
		}

		vector<vector<int>> dp(N, vector<int>(N, -1));

		function<int(int, int)> check = [&](int l, int r) {
			if (l == r || l + 1 == r) {
				return 1;
			}

			int& ans = dp[l][r];
			if (~ans)
				return ans;

			ans = 0;

			assert(l < r);
			for (int m = l; m < r; m++) {
				// [l, r] => [l, m] and [m + 1, r]
				int one = A[m] - (l ? A[l - 1] : 0);
				int two = A[r] - A[m];
				if ((one >= M || m == l) && (two >= M || m == r - 1)) {
					ans |= check(l, m) && check(m + 1, r);
				}
			}
			return ans;
		};

		return (bool)check(0, N - 1);
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> A = { 2, 2, 1 };
	cout << Solution::canSplitArray(A, 4) << '\n';
	vector<int> B = { 2, 1, 3 };
	cout << Solution::canSplitArray(B, 5) << '\n';
	vector<int> C = { 2, 3, 3, 2, 3 };
	cout << Solution::canSplitArray(C, 6) << '\n';

	return 0;
}

