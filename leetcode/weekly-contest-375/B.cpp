#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	vector<int> getGoodIndices(vector<vector<int>>& A, int T) {
		vector<int> answers;
		int i = 0;
		for (auto var : A) {
			int a = var[0], b = var[1], c = var[2], m = var[3];
			int result = 1;
			while (b--) {
				result = result * a % 10;
			}
			int final_result = 1;
			while (c--) {
				final_result = final_result * result % m;
			}
			if (final_result == T) {
				answers.push_back(i);
			}
			i++;
		}
		return answers;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
