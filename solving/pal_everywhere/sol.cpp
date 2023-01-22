/*
Author: Nachiket Kanore
Created: Monday 14 December 2020 11:52:30 AM IST
(ツ) Strength does not come from physical capacity. It comes from an indomitable will.
*/
#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

string a, b;
int n, m;
int dp[1002][1002];

int go(int i, int j) {
	if (i == n)
		return j >= 0;
	if (j == -1)
		return i < n;
	int& ans = dp[i][j];
	if (~ans)
		return ans;
	ans = 0;

	if (a[i] == b[j])
		ans = max(ans, 2 + go(i + 1, j - 1));
	ans = max(ans, go(i + 1, j));
	ans = max(ans, go(i, j - 1));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	n = sz(a), m = sz(b);
	memset(dp, -1, sizeof(dp));
	cout << go(0, m - 1);
}
