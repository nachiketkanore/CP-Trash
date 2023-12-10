#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	long long countSubarrays(vector<int> A, int K) {
		long long ans = 0;
		int mx = *max_element(A.begin(), A.end());
		const int N = A.size();
		vector<int> positions;
		for (int i = 0; i < N; i++) {
			if (A[i] == mx) {
				positions.push_back(i);
			}
		}

		int max_id = -1;
		for (int R = 0; R < N; R++) {
			if (A[R] == mx) {
				max_id = R;
			}
			if (max_id == -1)
				continue;
			int pos_id = lower_bound(positions.begin(), positions.end(), max_id) - positions.begin();
			assert(pos_id >= 0 && pos_id < (int)positions.size());
			int j = pos_id - K + 1;
			if (j >= 0 && j < (int)positions.size()) {
				int which_idx = positions[j];
				ans += which_idx + 1;
			}
		}

		return ans;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Solution sol;
	cout << sol.countSubarrays({ 1, 3, 2, 3, 3 }, 2) << endl;
	cout << sol.countSubarrays({ 1, 4, 2, 1 }, 3) << endl;
	return 0;
}
