#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	vector<int> dp;
	vector<string> A;
	string T;
	int N;

	int go(int done_mask) {
		if (done_mask == (1 << N) - 1)
			return 0;
		int& ans = dp[done_mask];
		if (~ans)
			return ans;
		ans = 1e9;

		for (string take : A) {
			vector<int> counts(26);
			for (char ch : take) {
				counts[ch - 'a']++;
			}
			int add_in_done_mask = 0;
			for (int i = 0; i < N; i++) {
				if ((done_mask >> i & 1) == 0 && counts[T[i] - 'a'] > 0) {
					counts[T[i] - 'a']--;
					add_in_done_mask |= 1 << i;
				}
			}

			assert((done_mask & add_in_done_mask) == 0);
			if (add_in_done_mask > 0) {
				ans = min(ans, 1 + go(done_mask | add_in_done_mask));
			}
		}
		return ans;
	}

	public:
	int minStickers(vector<string>& A, string T) {
		this->A = A;
		this->T = T;
		this->N = T.size();
		dp.resize(1 << this->N, -1);
		int ans = go(0);
		if (ans >= 1e9)
			ans = -1;
		return ans;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
