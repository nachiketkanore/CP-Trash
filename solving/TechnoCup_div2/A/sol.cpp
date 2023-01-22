/*
Author: NK
Created: Sunday 25 October 2020 04:31:06 PM IST
(ツ) Life is a process. We are a process. The universe is a process.
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
	int n;
	cin >> n;

	vector<int> a(n), ans(n);
	for (int& x : a)
		cin >> x;

	int lo = 0, hi = n - 1;
	while (lo < hi) {
		ans[lo] = a[hi];
		ans[hi] = -a[lo];
		lo++, hi--;
	}

	for (int x : ans)
		cout << x << " ";
	cout << "\n";
	return;

	assert(false);
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
