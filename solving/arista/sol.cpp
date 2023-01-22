/*
Author: Nachiket Kanore
Created: Monday 19 October 2020 09:31:32 AM IST
(ツ) The worst enemy to creativity is self-doubt.
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
vector<array<int, 3>> vals; // 0 for L, 1 for R, 2 for cost
int dp[N];

int go(int id) {
	if (id >= n)
		return 0;

	int& ans = dp[id];
	if (~ans)
		return ans;

	ans = -inf;

	int dont_take = go(id + 1);
	int take = vals[id][2];

	int right = vals[id][1];
	int next = -1;
	int lo = id + 1, hi = n;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (vals[mid][0] > right) {
			next = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	if (~next) {
		take += go(next);
	}

	ans = max(take, dont_take);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, -1, sizeof(dp));
	sort(vals.begin(), vals.end());
	int ans = go(0);
	cout << ans;
}
