/*
Author: Nachiket Kanore
Created: Friday 13 November 2020 08:04:58 PM IST
(ツ) All difficult things have their origin in that which is easy, and great things in that which is small.
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

void solve() {
	int n, m;
	cin >> n >> m;

	int mat[n + 2][m + 2];
	FOR(i, 0, n + 1) FOR(j, 0, m + 1) mat[i][j] = -10;

	FOR(i, 1, n) FOR(j, 1, m) cin >> mat[i][j];

	FOR(i, 1, n) FOR(j, 1, m) {
		bool left = mat[i][j - 1] == mat[i][j];
		bool right = mat[i][j + 1] == mat[i][j];
		bool up = mat[i - 1][j] == mat[i][j];
		bool down = mat[i + 1][j] == mat[i][j];

		if (mat[i][j - 1] == mat[i][j] + 1 || mat[i - 1][j] == mat[i][j] + 1)
			continue;
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
