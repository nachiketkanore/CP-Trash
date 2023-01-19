/*
Author: Nachiket Kanore
Created: Sunday 15 November 2020 05:06:22 PM IST
(ツ) Nothing in life is to be feared. It is only to be understood.
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

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> pos, neg, vals;
		FOR(i, 1, n) {
			int u;
			cin >> u;
			if (u >= 0)
				pos.push_back(u);
			else
				neg.push_back(u);
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());

		{
			int cnt = 5;
			while (cnt-- && sz(pos))
				vals.push_back(pos.back()), pos.pop_back();
		}
		{
			reverse(pos.begin(), pos.end());
			int cnt = 5;
			while (cnt-- && sz(pos))
				vals.push_back(pos.back()), pos.pop_back();
		}
		{
			int cnt = 5;
			while (cnt-- && sz(neg))
				vals.push_back(neg.back()), neg.pop_back();
		}
		{
			reverse(neg.begin(), neg.end());
			int cnt = 5;
			while (cnt-- && sz(neg))
				vals.push_back(neg.back()), neg.pop_back();
		}

		int ans = -inf;
		FOR(i, 1, sz(vals))
		FOR(j, i + 1, sz(vals))
		FOR(k, j + 1, sz(vals))
		FOR(l, k + 1, sz(vals))
		FOR(t, l + 1, sz(vals))
		ans = max(ans, vals[i - 1] * vals[j - 1] * vals[k - 1] * vals[l - 1] * vals[t - 1]);
		cout << ans << "\n";
	}
}
