/*
Author: Nachiket Kanore
Created: Tuesday 01 December 2020 11:43:27 AM IST
(ツ) Knowledge is a process of piling up facts; wisdom lies in their simplification.
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

const int N = 2e5 + 5, inf = 1e18;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	for (int& d : a)
		cin >> d;
	sort(a.rbegin(), a.rend());
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
	}

	using ld = long double;
	ld ans = 0;

	for (int i = 0; i < n; i += x) {
		if (i + x - 1 < n) {
			int sum = a[i + x - 1];
			if (i)
				sum -= a[i - 1];
			ans += (ld)sum / (ld)x;
		}
	}
	printf("%0.8Lf\n", ans);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
