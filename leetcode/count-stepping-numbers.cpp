// Problem link:
// https://leetcode.com/contest/weekly-contest-356/problems/count-stepping-numbers-in-range/
#include "bits/stdc++.h"
using namespace std;

class Solution {
	public:
	const int MOD = 1e9 + 7;
	int dp[2][11][100];

	int solve(const string& num, int id = 0, bool small = false, int prev = -1) {
		if (id == (int)num.size()) {
			return 1;
		}
		int& ans = dp[small][prev == -1 ? 10 : prev][id];
		if (~ans)
			return ans;
		ans = 0;
		const int curr = (int)(num[id] - '0');

		int lo = 0, hi = small ? 9 : curr;
		for (int put = lo; put <= hi; put++) {
			if (prev == -1) {
				ans += solve(num, id + 1, small || (put < curr), put == 0 ? -1 : put);
				if (ans >= MOD)
					ans -= MOD;
			} else {
				if (abs(prev - put) == 1) {
					ans += solve(num, id + 1, small || (put < curr), put);
					if (ans >= MOD)
						ans -= MOD;
				}
			}
		}

		return ans;
	}

	int check_separate(const string& num) {
		bool valid = true;
		for (int i = 1; i < (int)num.size(); i++) {
			valid &= abs(num[i - 1] - num[i]) == 1;
		}
		return valid;
	}
	int solve_w(const string& s) {
		memset(dp, -1, sizeof(dp));
		return solve(s);
	}
	int countSteppingNumbers(string low, string high) {
		return (solve_w(high) - solve_w(low) + check_separate(low) + MOD) % MOD;
	}
};

int main() {
	Solution solution;
	cout << solution.countSteppingNumbers("1", "11") << '\n';
	cout << solution.countSteppingNumbers("90", "101") << '\n';
	return 0;
}
