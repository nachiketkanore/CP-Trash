/*
Author: Nachiket Kanore
Created: Sunday 13 December 2020 12:19:01 PM IST
(ツ) You learn to speak by speaking, to study by studying, to run by running, to work by working; in just the same way, you learn to love by loving.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <string>
#include <array>

#define int long long
#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e5 + 5, inf = 1e18;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<array<int,2>> a(n);
	for (auto &it : a) cin >> it[0] >> it[1];

	sort(a.begin(), a.end());

	int ans = 0;

	for (auto &it : a) {
		if (m == 0) break;
		int want = min(m, it[1]);
		ans += want * it[0];
		m -= want;
	}

	cout << ans;
}
