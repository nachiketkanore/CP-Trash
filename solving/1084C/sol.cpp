/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 04:23:25 PM IST
(ツ) No alibi will save you from accepting the responsibility.
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

const int N = 1e5 + 2, mod = 1e9 + 7;

string s;
int n;
int dp[2][N];

int go(int id, int canTake) {
	if (id == n)
		return 1;
	int& ans = dp[canTake][id];
	if (~ans)
		return ans;
	ans = 0;
	if (s[id] == 'a' && canTake) {
		ans = (ans + go(id + 1, 0)) % mod;
		ans = (ans + go(id + 1, 1)) % mod;
	} else {
		ans = (ans + go(id + 1, canTake || s[id] == 'b')) % mod;
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	n = sz(s);
	memset(dp, -1, sizeof(dp));
	int ans = (go(0, 1) - 1 + mod) % mod;
	cout << ans;
}
