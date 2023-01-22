/*
Author: Nachiket Kanore
Created: Sunday 31 January 2021 10:47:53 PM IST
(ツ) As we express our gratitude, we must never forget that the highest appreciation is not to utter words, but to live by them.
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
#define pb push_back
#define ALL(x) (x).begin(), (x).end()
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

template <class T> bool cmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template <class T> bool cmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}

const int N = 5e5 + 5, inf = 1e18;

int n, a[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	FOR(i, 1, n) cin >> a[i];

	auto solve = [&](int ans) {
		vector<pair<int, int>> v;
		for (int i = 1; i <= n; i++) {
			while (!v.empty() && v.back().first >= a[i]) {
				v.pop_back();
			}
			if (!v.empty()) {
				ans += i - v.back().second;
			}
			v.push_back({ a[i], i });
		}
		return ans;
	};

	int ans = solve(0);
	reverse(a + 1, a + n + 1);
	ans += solve(0);
	cout << ans;
}
