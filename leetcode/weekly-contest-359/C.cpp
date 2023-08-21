#include "bits/stdc++.h"
#include <cmath>
using namespace std;

class Solution {
	public:
	int n;
	vector<array<int, 3>> A;
	vector<int> dp;
	int go(int id) {
		if (id >= (int)A.size())
			return 0;
		int& ans = dp[id];
		if (ans != -1)
			return ans;
		ans = 0;
		{
			int c1 = go(id + 1);
			ans = max(ans, c1);
		}
		auto [L, R, cost] = A[id];
		int c2 = cost;
		int nid = lower_bound(A.begin() + id + 1, A.end(), array<int, 3>{ R + 1, 0, 0 }) - A.begin();
		if (nid > id && nid < n) {
			c2 += go(nid);
		}
		ans = max(ans, c2);

		return ans;
	}
	int maximizeTheProfit(int n, vector<vector<int>>& offers) {
		A.clear();
		// this was so annoying
		// i thought n = offers.size() is given
		n = offers.size();
		for (auto x : offers)
			A.push_back({ x[0], x[1], x[2] });
		sort(A.begin(), A.end());
		this->n = n;
		dp.assign(n, -1);
		return go(0);
	}
};
class SolutionNaive {
	public:
	int maximizeTheProfit(int n, vector<vector<int>>& offers) {
		n = offers.size();
		vector<int> dp(n);
		sort(offers.begin(), offers.end(), [&](auto one, auto two) { return one[0] < two[0]; });
		for (int i = 0; i < n; i++) {
			int l = offers[i][0], cost = offers[i][2];
			dp[i] = cost;
			for (int j = i - 1; j >= 0; --j) {
				if (offers[j][1] < l) {
					dp[i] = max(dp[i], dp[j] + cost);
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solution s;
	vector<vector<int>> A = { { 0, 0, 1 }, { 0, 2, 2 }, { 1, 3, 2 } };
	cout << s.maximizeTheProfit(3, A) << '\n';
	A = { { 0, 0, 1 }, { 0, 2, 10 }, { 1, 3, 2 } };
	cout << s.maximizeTheProfit(3, A) << '\n';
	// cout << s.maximizeTheProfit(3, A) << '\n';
	return 0;
}
