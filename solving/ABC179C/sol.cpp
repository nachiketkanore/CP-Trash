/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 03:14:38 PM IST
(ツ) The cause is hidden. The effect is visible to all.
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

const int N = 1e6 + 5, inf = 1e18;

int divs[N + 1];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	FOR(i, 1, N) for (int m = i; m <= N; m += i) divs[m]++;

	int n;
	cin >> n;
	int ans = 0;

	FOR(c, 1, n - 1) {
		int ab = n - c;
		ans += divs[ab];
	}
	cout << ans;
}
