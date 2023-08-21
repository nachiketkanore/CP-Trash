#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	int longestEqualSubarray(vector<int>& A, int K) {
		// say for any two elements A[i] and A[j] in array
		// where A[i] == A[j]
		// we keep all the elements in the range i..j equal to A[i]
		// and delete the rest
		// account this length if elements to delete is <= K
		const int N = A.size();
		vector<vector<int>> positions(N + 1);
		for (int i = 0; i < N; i++) {
			positions[A[i]].push_back(i);
		}

		int ans = 0;

		for (int val = 1; val <= N; val++) {
			const vector<int>& pos = positions[val];
			// iterate on positions of this val
			const int M = pos.size();
			for (int i = 0; i < M; i++) {
				// let's binary search on the right point position
				int curr_pos = pos[i];
				int lo = i, hi = M - 1;
				int j = -1;
				while (lo <= hi) {
					int mid = (lo + hi) / 2;
					int len = (pos[mid] - pos[i] + 1);
					int keep = mid - i + 1;
					int del = len - keep;
					if (del <= K) {
						j = mid;
						lo = mid + 1;
					} else {
						hi = mid - 1;
					}
				}
				assert(~j);
				int len = (pos[j] - pos[i] + 1);
				int keep = j - i + 1;
				int del = len - keep;
				assert(del <= K);
				ans = max(ans, keep);
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

