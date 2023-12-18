#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	int maxFrequencyScore(vector<int>& A, long long K) {
		int ans = 0;
		for (int x : A) {
			vector<int> diffs;
			for (int y : A) {
				diffs.push_back(abs(x - y));
			}
			sort(diffs.begin(), diffs.end());
			int cnt = 0, sum = 0;
			for (int d : diffs) {
				if (sum + d <= K) {
					++cnt;
					sum += d;
				} else {
					break;
				}
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
