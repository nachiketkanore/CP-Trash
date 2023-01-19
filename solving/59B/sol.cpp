/*
Author: Nachiket Kanore
Created: Friday 20 November 2020 03:00:16 PM IST
(ツ) Time is the wisest counsellor of all.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
vector<int> a;
int dp[2][101];

int go(int id, int rem) {
	if (id == n)
		return (rem == 1 ? 0 : -inf);
	int& ans = dp[rem][id];
	if (~ans)
		return ans;
	ans = -inf;
	ans = max(ans, go(id + 1, rem));
	ans = max(ans, a[id] + go(id + 1, (rem + a[id]) % 2));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// Finding max. odd sum of subsequence
	cin >> n;
	a.resize(n);
	for (int& x : a)
		cin >> x;
	memset(dp, -1, sizeof(dp));
	int ans = go(0, 0);
	if (ans <= 0)
		ans = 0;
	cout << ans << "\n";
}
