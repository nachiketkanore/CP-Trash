#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int maxScore(vector<int>& A) {
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		long long pref = 0, ans = 0;
		for (int x : A) {
			pref += x;
			if (pref > 0) {
				++ans;
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

