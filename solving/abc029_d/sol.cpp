/*
Author: Nachiket Kanore
Created: Friday 04 December 2020 10:17:46 PM IST
(ツ) By accepting yourself and being fully what you are, your presence can make others happy.
*/
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

string n;
int dp[20][2][20];

int go(int id, int smallTaken, int ones) {
	if (id == sz(n))
		return ones;
	int& ans = dp[id][smallTaken][ones];
	if (~ans)
		return ans;
	ans = 0;

	int from = 0;
	int to = smallTaken ? 9 : (n[id] - '0');

	FOR(dig, from, to) {
		int get = go(id + 1, smallTaken || (dig < n[id] - '0'), ones + (dig == 1));
		ans += get;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	int ans = go(0, 0, 0);
	cout << ans << "\n";
}
