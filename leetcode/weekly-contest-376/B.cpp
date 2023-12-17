#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	vector<vector<int>> divideArray(vector<int>& A, int K) {
		const int N = A.size();
		sort(A.begin(), A.end());
		vector<vector<int>> answer;
		for (int i = 0; i + 2 < N; i += 3) {
			if (A[i + 2] - A[i] <= K) {
				answer.push_back({ A[i], A[i + 1], A[i + 2] });
			} else {
				return {};
			}
		}
		return answer;
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
