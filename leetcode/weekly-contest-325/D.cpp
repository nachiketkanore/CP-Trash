#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// we can count subsets with sums <= 1000
// then that subset is considered group 1
// and the other group = TOTAL - gsum
// how to handle subsets with sum > 1000 ?

// other way to think about this:
// count(>= K, >= K) =
// total (2^N - 1) minus
//	- count(< K, < K) - count(< K, >= K) - count(>= K, < K)
// 2 and 3 are same?

class Solution {
	public:
	int N, K;
	long long tot;
	vector<int> A;
	const int MOD = 1e9 + 7;
	int dp[1000][1001];

	int go1(int id, int sum) {
		if (sum >= K)
			return 0;
		if (id == N) {
			return sum < K && (tot - sum) < K;
		}
		int& ans = dp[id][sum];
		if (~ans)
			return ans;
		ans = (go1(id + 1, sum) + go1(id + 1, sum + A[id])) % MOD;
		return ans;
	}

	int go2(int id, int sum) {
		if (sum >= K)
			return 0;
		if (id == N) {
			return sum < K && (tot - sum) >= K;
		}
		int& ans = dp[id][sum];
		if (~ans)
			return ans;
		ans = (go2(id + 1, sum) + go2(id + 1, sum + A[id])) % MOD;
		return ans;
	}

	int countPartitions(vector<int>& A, int K) {
		this->N = A.size();
		this->A = A;
		this->K = K;
		this->tot = accumulate(A.begin(), A.end(), 0LL);

		int tot = power(2, N, MOD);
		reset_dp();
		int c1 = go1(0, 0);
		reset_dp();
		int c2 = 2 * go2(0, 0) % MOD;

		int ans = (1ll * tot - c1 - c2 + MOD + MOD) % MOD;
		return ans;
	}

	void reset_dp() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= 1000; j++) {
				dp[i][j] = -1;
			}
		}
	}

	int power(int a, int b, int MOD) {
		int ret = 1;
		while (b--)
			ret = (1ll * ret * a) % MOD;
		return ret;
	}
};

int32_t main() {

	Solution S;
	vector<int> A = { 1, 2, 3, 4 };
	cout << S.countPartitions(A, 4) << '\n';
	A = { 3, 3, 3 };
	cout << S.countPartitions(A, 4) << '\n';
	A = { 6, 6 };
	cout << S.countPartitions(A, 2) << '\n';
}
