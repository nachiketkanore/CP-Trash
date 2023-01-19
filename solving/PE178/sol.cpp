/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 01:28:10 AM IST
(ツ) However many holy words you read, However many you speak, What good will they do you If you do not act on upon them?
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

const int N = 2e5 + 5, inf = 1e14;

string s;
int n;
int dp[2][2][42][10][1 << 11];

int go(int id, int prev, int mask, bool smallTaken, bool nonZeroTaken) {
	if (id == sz(s)) {
		return __builtin_popcountll(mask) == 10;
	}

	int& ans = dp[smallTaken][nonZeroTaken][id][prev][mask];
	if (~ans)
		return ans;
	ans = 0;

	int curr = s[id] - '0';
	int from = -1, to = -1;
	if (smallTaken) {
		from = 0, to = 9;
	} else {
		from = 0, to = curr;
	}

	FOR(dig, from, to) {
		if (abs(dig - prev) != 1 && nonZeroTaken)
			continue;
		int next_id = id + 1;
		int next_prev = dig;
		int next_mask = mask;
		if (nonZeroTaken || dig)
			next_mask |= (1 << dig);

		bool next_smallTaken = smallTaken || (dig < curr);
		bool next_nonZeroTaken = nonZeroTaken || dig;
		int get = go(next_id, next_prev, next_mask, next_smallTaken, next_nonZeroTaken);
		ans = ans + get;
	}
	return ans;
}

void calc() {
	n = sz(s);
	int ans = 0;
	memset(dp, -1, sizeof(dp));

	FOR(dig, 0, 9) {
		int first = s[0] - '0';
		if (dig > first)
			continue;
		int id = 1;
		int prev = dig;
		int mask = (dig > 0 ? (1 << dig) : 0);
		bool smallTaken = (dig < first);
		bool nonZeroTaken = (dig != 0);
		int get = go(id, prev, mask, smallTaken, nonZeroTaken);
		ans = ans + get;
	}

	cout << "TOTAL = " << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	s = "1";
	FOR(i, 1, 40) s += "0";
	calc();
}