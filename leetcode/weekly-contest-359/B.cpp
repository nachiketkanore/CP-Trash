#include <bits/stdc++.h>
#define int int64_t
using namespace std;

class Solution {
	public:
	int minimumSum(int n, int k) {
		int sum = 0;
		set<int> taken;
		for (int put = 1; n > 0; put++) {
			// put + other = k
			int other = k - put;
			if (!taken.count(other)) {
				taken.insert(put);
				sum += put;
				n--;
			}
		}
		return sum;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}

