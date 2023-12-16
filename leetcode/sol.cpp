#include <bits/stdc++.h>
#define int int64_t
using namespace std;

long long dp[5][1000][1000];
class Solution {
	int N;
	vector<int> A;

	public:
	long long go(int curr, int prev, int cnt) {
		// base cases
		if (cnt > 4)
			return 0;
		if (curr == N) {
			return cnt == 4;
		}
		long long& ways = dp[cnt][curr][prev];
		if (ways != -1)
			return ways;
		ways = 0;

		// consider A[curr] in the construction
		long long choice1 = 0;
		if (A[curr] > A[prev]) {
			choice1 = go(curr + 1, curr, cnt + 1);
		}

		// dont consider A[curr] in the construction
		long long choice2 = go(curr + 1, prev, cnt);

		return ways = choice1 + choice2;
	}

	long long countQuadruplets(vector<int> A) {
		this->A = A;
		this->N = A.size();

		memset(dp, -1, sizeof(dp));
		long long ans = 0;
		for (int i1 = 0; i1 < N; i1++) {
			ans += go(i1 + 1, i1, 1);
		}
		return ans;
	}
};
int32_t main() {

	Solution solution;

	cout << solution.countQuadruplets({ 1, 3, 2, 4, 5 }) << endl;
	cout << solution.countQuadruplets({ 1, 2, 3, 4 }) << endl;

	return 0;
}
