#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	int countTestedDevices(vector<int>& A) {
		int decrease = 0, ans = 0;
		for (int x : A) {
			if (x - decrease > 0) {
				++ans;
				decrease++;
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
