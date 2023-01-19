/*
Author: Nachiket Kanore
Created: Wednesday 21 October 2020 12:45:12 AM IST
(ツ) If you change the way you look at things, the things you look at change.
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

const int N = 1e3 + 5, inf = 1e18, mod = 1e9 + 7;

string s;
int k;
int dp[2][2][N][N];

int ok(int val) {
	int req = 0;
	while (val > 1) {
		req++;
		val = __builtin_popcountll(val);
	}
	return req == k - 1;
}

int go(int id, int smallTaken, int bits, bool taken) {
	if (id == sz(s)) {
		if (bits == 0)
			return 0;
		return ok(bits);
	}
	int& ans = dp[smallTaken][taken][id][bits];
	if (~ans)
		return ans;
	ans = 0;
	int from = -1, to = -1;

	if (smallTaken)
		from = 0, to = 1;
	else
		from = 0, to = s[id] - '0';

	FOR(dig, from, to) {
		int get = go(id + 1, smallTaken || (dig < s[id] - '0'), bits + (dig == 1), taken || dig);
		ans = (ans + get) % mod;
	}

	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	cin >> k;

	if (k == 0) {
		cout << "1\n";
		return 0;
	}

	memset(dp, -1, sizeof(dp));
	// Count numbers <= s with f(i) == k
	int ans = go(0, 0, 0, 0);
	if (k == 1) {
		ans = (ans - 1 + mod) % mod;
	}
	cout << ans;
}
