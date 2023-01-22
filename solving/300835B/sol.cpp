/*
Author: Nachiket Kanore
Created: Monday 26 October 2020 07:14:21 PM IST
(ツ) Genuine love should first be directed at oneself if we do not love ourselves, how can we love others?
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

vector<int> cols[N];

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	int left = inf;

	FOR(i, 1, k) {
		int u, v;
		cin >> u >> v;
		left = min(left, v);
		cols[v].push_back(u);
	}

	int mn = inf, ans = 0;

	FOR(col, left, m) {
		sort(cols[col].begin(), cols[col].end());
		if (sz(cols[col])) {
			mn = min(mn, cols[col].front());
		}

		int cnt = (n - mn + 1);
		assert(cnt >= 1);
		ans += cnt;
	}

	cout << ans;
}
