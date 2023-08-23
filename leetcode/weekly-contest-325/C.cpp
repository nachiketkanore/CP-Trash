#include "bits/stdc++.h"
using namespace std;

class Solution {
	public:
	int maximumTastiness(vector<int>& A, int K) {
		const int N = A.size();
		sort(A.begin(), A.end());

		auto possible = [&](int diff) {
			int take = K - 1;
			int last = A[0];
			for (int i = 1; i < N; i++) {
				if (A[i] - last >= diff) {
					take--;
					last = A[i];
				}
			}
			return take <= 0;
		};

		int lo = 0, hi = 1e9;
		int ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (possible(mid)) {
				ans = mid;
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		return ans;
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
