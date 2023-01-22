/*
Author: Nachiket Kanore
Created: Thursday 19 November 2020 03:19:04 PM IST
(ツ) We know from science that nothing in the universe exists as an isolated or independent entity.
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

int n, a[N], best[N];
int ans = -inf;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int curr = 0;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i];
		a[i] += a[i - 1];
		best[i] = max(best[i], a[i]);
		best[i] = max(best[i - 1], best[i]);
	}
	ans = max(ans, curr);
	FOR(i, 1, n) {
		ans = max(ans, curr + best[i]);
		curr += a[i];
		cerr << curr << "\n";
		ans = max(ans, curr);
	}
	cout << ans;
}
