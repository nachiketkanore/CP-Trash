#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	vector<int> findMissingAndRepeatedValues(vector<vector<int>>& mat) {
		const int N = mat.size();
		vector<int> answer;

		for (int cnt_search : { 2, 0 }) {
			for (int search = 1; search <= N * N; search++) {
				int cnt = 0;
				for (const auto& row : mat) {
					cnt += count(row.begin(), row.end(), search);
				}
				if (cnt == cnt_search) {
					answer.push_back(search);
				}
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
