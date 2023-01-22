/*
Author: Nachiket Kanore
Created: Wednesday 18 November 2020 01:22:15 PM IST
(ツ) Problems are only opportunities with thorns on them.
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

	int k, m, n;
	cin >> k >> m >> n;
	int want_apples = max(0LL, 10 * k - n);
	int basket_req = (want_apples + m - 1) / m;
	cout << basket_req << "\n";
}
