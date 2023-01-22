/*
Author: Nachiket Kanore
Created: Thursday 15 October 2020 11:59:48 AM IST
(ツ) The smallest flower is a thought, a life answering to some feature of the Great Whole, of whom they have a persistent intuition.
*/
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7;

int r, g, sum;
int dp[2][N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> g;
	sum = r + g;

	int h = 0;
	while ((h + 1) * (h + 2) / 2 <= sum)
		++h;

	FOR(takenReds, 0, r) {
		int tot = h * (h + 1) / 2;
		int remainReds = r - takenReds;
		int remainGreens = tot - remainReds;
		if (remainGreens <= g) {
			dp[0][takenReds] = 1;
		}
	}

	FOR(level, 1, h) {
		FOR(takeReds, 0, r) {
			dp[level & 1][takeReds] = dp[(level - 1) & 1][takeReds];
			if (takeReds - level >= 0) {
				dp[level & 1][takeReds] += dp[(level - 1) & 1][takeReds - level];
			}
			dp[0][takeReds] %= mod;
			dp[1][takeReds] %= mod;
		}
	}
	cout << dp[h & 1][r];
}
