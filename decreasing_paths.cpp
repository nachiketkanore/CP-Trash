/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 04:09:32 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

const int _ = 1002;
const int MOD = 1e9 + 7;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int N, mat[_][_], dp[_][_];

int go(int i, int j) {
	if (!(1 <= i && i <= N && 1 <= j && j <= N))
		return 0;
	int& ans = dp[i][j];
	if (ans > 0)
		return ans;
	ans = 1;
	F0R(id, 4) {
		int ni = i + dx[id];
		int nj = j + dy[id];
		if (!(1 <= ni && ni <= N && 1 <= nj && nj <= N))
			continue;
		if (mat[ni][nj] < mat[i][j])
			ans += go(ni, nj);
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	FOR(i, 1, N) FOR(j, 1, N) cin >> mat[i][j];
	memset(dp, -1, sizeof(dp));

	int ans = 0;
	FOR(i, 1, N) FOR(j, 1, N) {
		ans += (~dp[i][j] ? dp[i][j] : go(i, j));
		if (ans >= MOD) {
			ans -= MOD;
		}
	}
	cout << ans << '\n';
}
