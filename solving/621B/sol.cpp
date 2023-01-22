/*
Author: Nachiket Kanore
Created: Thursday 22 October 2020 10:47:15 AM IST
(ツ) He who knows, does not speak. He who speaks, does not know.
*/
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int n;
map<int, int> cnt1, cnt2;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		cnt1[x - y]++;
		cnt2[x + y]++;
	}

	int ans = 0;

	for (auto [d, cnt] : cnt1) {
		ans += cnt * (cnt - 1) / 2;
	}

	for (auto [d, cnt] : cnt2) {
		ans += cnt * (cnt - 1) / 2;
	}

	cout << ans << '\n';
}
