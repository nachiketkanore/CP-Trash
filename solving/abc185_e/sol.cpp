/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 07:13:59 PM IST
(ツ) I cannot say whether things will get better if we change; what I can say is they must change if they are to get better.
*/
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1002, inf = 1e18;

int n, m;
int a[N], b[N];
int dp[N][N];

int go(int i, int j) {
	if (i > n)
		return m - j + 1;
	if (j > m)
		return n - i + 1;
	int& ans = dp[i][j];
	if (~ans)
		return ans;
	ans = inf;

	int c1 = (a[i] != b[j]) + go(i + 1, j + 1);
	int c2 = 1 + go(i, j + 1);
	int c3 = 1 + go(i + 1, j);
	int c4 = 2 + go(i + 1, j + 1);

	ans = min({ ans, c1, c2, c3, c4 });
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, m) cin >> b[i];
	cout << go(1, 1) << "\n";
}
