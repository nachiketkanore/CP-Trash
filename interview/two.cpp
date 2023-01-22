#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int l, int r, vector<vector<int>>& dp) {
	if (l >= r)
		return 0;
	if (dp[l][r] != -1)
		return dp[l][r];

	int ans = 0;

	for (int i = l; i < r; i++) {
		int temp = solve(nums, l, i, dp) + solve(nums, i + 1, r, dp) + nums[l - 1] * nums[i] * nums[r];
		ans = max(ans, temp);
	}
	return dp[l][r] = ans;
}

int coins(vector<int>& zombie) {
	zombie.insert(zombie.begin(), 1);
	zombie.push_back(1);
	int n = zombie.size();

	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(zombie, 1, n - 1, dp);
}

int main() {
	vector<int> A{ 5, 1, 3, 9 };
	cout << coins(A);
	return 0;
}
