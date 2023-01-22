/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 07:25:09 PM IST
(ツ) The conditions of conquest are always easy. We have but to toil awhile, endure awhile, believe always, and never turn back.
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

int n, a[N], k, from;

bool ok(int make) {
	int req = 0;

	FOR(i, from, n) {
		if (req > k)
			return false;
		if (a[i] < make)
			req += make - a[i];
	}

	return req <= k;
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	FOR(i, 1, n) {
		cin >> a[i];
	}

	sort(a + 1, a + n + 1);

	from = (n + 1) >> 1;

	int lo = 0, hi = inf;
	int ans = -1;

	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (ok(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	assert(~ans);
	cout << ans;
}
