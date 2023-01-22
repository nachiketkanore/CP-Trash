/*
Author: Nachiket Kanore
Created: Tuesday 24 November 2020 02:41:02 PM IST
(ツ) There are only two ways to live your life. One is as though nothing is a miracle. The other is as though everything is a miracle.
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

const int N = 255, inf = 1e18;

int n, k, a[N], pre[N][N];
int dp[N][N];

int go(int id, int done) {
	if (done > k)
		return -inf;
	if (id == n + 1)
		return (done == k ? 0 : -inf);
	int& ans = dp[id][done];
	if (~ans)
		return ans;
	ans = -inf;
	FOR(to, id, n)
	ans = max(ans, pre[id][to] + go(to + 1, done + 1));
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k;
		FOR(i, 1, n) {
			cin >> a[i];
			pre[i][i] = a[i];
			for (int j = i - 1; j; j--)
				pre[j][i] = __gcd(a[j], pre[j + 1][i]);
		}
		FOR(i, 0, n) FOR(j, 0, k) dp[i][j] = -1;
		int ans = go(1, 0);
		cout << ans << "\n";
	}
}
