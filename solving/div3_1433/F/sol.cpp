/*
Author: Nachiket Kanore
Created: Tuesday 20 October 2020 08:56:23 PM IST
(ツ) Success in business requires training and discipline and hard work. But if you're not frightened by these things, the opportunities are just as great today as they ever were.
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

const int N = 70 + 2, inf = 1e18;

int n, m, k, mat[N][N];
int mx;
int dp[N][N][N][N];

int go(int row, int col, int chosen, int mod) {
	if (chosen > mx)
		return -inf;
	if (row == n + 1) {
		return (mod == 0 ? 0 : -inf);
	}

	int& ret = dp[row][col][chosen][mod];
	if (~ret)
		return ret;

	if (col > m)
		return ret = go(row + 1, 1, 0, mod);

	int ans = -inf;

	// take

	int c1 = mat[row][col] + go(row, col + 1, chosen + 1, (mod + mat[row][col]) % k);

	// dont take

	int c2 = go(row, col + 1, chosen, mod);

	// stop here

	int c3 = go(row + 1, 1, 0, mod);

	ans = max({ ans, c1, c2, c3 });
	ret = ans;
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	mx = m / 2;

	FOR(i, 1, n) FOR(j, 1, m) cin >> mat[i][j];

	memset(dp, -1, sizeof(dp));
	int ans = 0;
	ans = max(ans, go(1, 1, 0, 0));
	cout << ans;
}
