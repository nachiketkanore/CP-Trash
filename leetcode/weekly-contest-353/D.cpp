#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	bool checkArray(vector<int>& A, int K) {
		const int N = A.size();
		int pref = 0;
		vector<int> C(N, 0);
		for (int i = 0; i < N; i++) {
			pref += C[i];
			A[i] += pref;
			if (A[i] > 0) {
				if (i + K - 1 >= N)
					return false;
				if (i + 1 < N)
					C[i + 1] -= A[i];
				if (i + K < N)
					C[i + K] += A[i];
				A[i] = 0;
			} else if (A[i] < 0) {
				return false;
			}
		}

		return true;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solution s;
	vector<int> A = { 2, 2, 3, 1, 1, 0 };
	cout << s.checkArray(A, 3) << '\n';
	A = { 1, 3, 1, 1 };
	cout << s.checkArray(A, 2) << '\n';
	return 0;
}
