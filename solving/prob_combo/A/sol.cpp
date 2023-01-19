/*
Author: Nachiket Kanore
Created: Thursday 03 December 2020 12:47:07 PM IST
(ツ) Give thanks for the rain of life that propels us to reach new horizons.
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

const int N = 55, inf = 1e18;

int n, m;
int row[2][N];
int col[2][N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			int val;
			cin >> val;
			row[val][i]++;
			col[val][j]++;
		}
	}

	int ans = 0;

	FOR(i, 1, n) {
		int zero = row[0][i];
		int one = row[1][i];
		ans += (1LL << zero) - 1;
		ans += (1LL << one) - 1;
	}

	FOR(i, 1, m) {
		int zero = col[0][i];
		int one = col[1][i];
		ans += (1LL << zero) - 1;
		ans += (1LL << one) - 1;
	}
	ans -= n * m;
	cout << ans << "\n";
}
