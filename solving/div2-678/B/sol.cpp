/*
Author: Nachiket Kanore
Created: Saturday 24 October 2020 07:22:57 PM IST
(ツ) The worst bankrupt in the world is the person who has lost his enthusiasm.
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

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;

		int mat[n + 2][n + 2];

		FOR(i, 1, n) FOR(j, 1, n) {
			if (i == j || (i == j - 1) || (i == n && j == 1))
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}

		FOR(i, 1, n) FOR(j, 1, n) cout << mat[i][j] << " \n"[j == n];
	}
}
