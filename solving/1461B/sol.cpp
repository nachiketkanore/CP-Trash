/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 12:47:26 AM IST
(ツ) If we have a positive mental attitude, then even when surrounded by hostility, we shall not lack inner peace.
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

const int N = 502, inf = 1e18;

int n, m;
bool mat[N][N];
bool dp[N][N][N], vis[N][N][N];

bool go(int i, int L, int R) {
	int len = R - L + 1;
	assert(len & 1);
	assert(L <= R);
	if (i == 0 || !mat[i][L] || !mat[i][R])
		return false;
	if (L == R)
		return mat[i][L];
	if (vis[i][L][R])
		return dp[i][L][R];
	vis[i][L][R] = true;
	bool ans = go(i - 1, L + 1, R - 1) && go(i, L + 1, R - 1);
	return dp[i][L][R] = ans;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		FOR(i, 1, n) FOR(j, 1, m) {
			char ch;
			cin >> ch;
			mat[i][j] = ch == '*';
			FOR(len, 0, m)
			vis[i][j][len] = false;
		}
		int ans = 0;
		FOR(i, 1, n) FOR(j, 1, m) FOR(len, 0, m) {
			int L = j - len;
			int R = j + len;
			if (L < 0 || R > m)
				break;
			ans += go(i, L, R);
		}
		cout << ans << "\n";
	}
}
