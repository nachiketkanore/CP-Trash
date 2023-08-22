#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int closetTarget(vector<string>& A, string T, int id) {
		const int N = A.size();
		if (find(A.begin(), A.end(), T) == A.end()) {
			return -1;
		}
		int ans = N;
		for (int dir : { -1, +1 }) {
			int cost = 0, curr(id);
			while (A[curr] != T) {
				++cost;
				curr = (curr + dir + N) % N;
			}
			ans = min(ans, cost);
		}
		return ans;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}

