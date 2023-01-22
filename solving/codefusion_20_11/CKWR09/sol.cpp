/*
Author: Nachiket Kanore
Created: Tuesday 01 December 2020 12:29:09 PM IST
(ツ) You have to do your own growing no matter how tall your grandfather was.
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 1e5 + 5, inf = 1e18;

int n;
int a[2][N];
int dp[2][N];

int go(int which, int id) {
	if (id > n)
		return 0;
	int& ans = dp[which][id];
	if (~ans)
		return ans;
	ans = inf;

	FOR(jump, 1, a[which][id])
	ans = min(ans, 1 + go(which ^ 1, id + jump));
	return ans;
}

void solve() {
	cin >> n;
	FOR(i, 1, n) cin >> a[0][i], dp[0][i] = -1;
	FOR(i, 1, n) cin >> a[1][i], dp[1][i] = -1;
	int ans = min(go(0, 1), go(1, 1));
	if (ans >= inf)
		ans = -1;
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
