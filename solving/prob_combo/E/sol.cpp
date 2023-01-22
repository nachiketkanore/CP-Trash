/*
Author: Nachiket Kanore
Created: Monday 07 December 2020 08:10:11 PM IST
(ツ) Life is a learning experience, only if you learn.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <math.h>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e3 + 5, inf = 1e18;

using ld = long double;

int n, t;
ld p;

ld dp[2005][2005];
bool vis[2005][2005];

ld go(int idx, int num) {
	if (idx == t)
		return num;
	if (vis[idx][num])
		return dp[idx][num];
	vis[idx][num] = true;
	return dp[idx][num] = p * go(idx + 1, num + (num < n ? 1 : 0)) + (1.0 - p) * go(idx + 1, num);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> t;
	printf("%0.10Lf\n", go(0, 0));
}
