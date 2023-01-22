/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 02:56:18 PM IST
(ツ) The universe is made of stories, not atoms.
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

const int N = 1e5 + 5, inf = 1e18;

int n, a[N];
int dp[2][N];

int go(int id, int prev) {
	if (id == n + 1)
		return 0;
	int& ans = dp[prev][id];
	if (~ans)
		return ans;
	ans = 0;
	if (prev == 0 && a[id] > 0)
		ans = 1 + go(id + 1, 1);
	if (prev == 1 && a[id] < 0)
		ans = 1 + go(id + 1, 0);
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		FOR(i, 1, n) {
			cin >> a[i];
			dp[0][i] = dp[1][i] = -1;
		}
		FOR(i, 1, n) {
			cout << max(go(i, 0), go(i, 1)) << " \n"[i == n];
		}
	}
}
