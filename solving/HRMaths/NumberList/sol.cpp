/**
 *	Author: Nachiket Kanore
 *	Created: Saturday 24 April 2021 12:51:20 AM IST
 **/
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#define int int64_t
#define pb push_back
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int inf = 1e18;
const int N = 5e5 + 5;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), ids;
	F0R(i, n) {
		cin >> a[i];
		if (a[i] > k) {
			ids.push_back(i);
		}
	}
	int ans = 0;
	F0R(i, n) {
		int id = lower_bound(ALL(ids), i) - ids.begin();
		if (id >= sz(ids))
			continue;
		id = ids[id];
		ans += n - id;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
		solve();
}
