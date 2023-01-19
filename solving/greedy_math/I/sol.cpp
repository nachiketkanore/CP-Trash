/*
Author: Nachiket Kanore
Created: Sunday 25 October 2020 09:21:38 PM IST
(ツ) The more light you allow within you, the brighter the world you live in will be.
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

const int N = 2e5 + 5, inf = 1e16;

void solve() {
	int n, tot;
	cin >> n >> tot;

	pair<int, int> vals[n + 2];

	FOR(i, 1, n) {
		cin >> vals[i].first >> vals[i].second;
	}

	sort(vals + 1, vals + n + 1);

	int md = (n + 1) >> 1;

	int ans = -1;

	auto ok = [&](int median) {
		int cost = 0;
		cout << median << "\n";

		FOR(i, 1, n) {
			int L = vals[i].first;
			int R = vals[i].second;

			if (i < md) {
				if (L <= median) {
					cost += L;
				} else {
					cout << median << " " << L << " " << R << " 1\n";
					return false;
				}
			} else {
				if (L <= median and median <= R) {
					cost += median;
				} else if (R < median) {
					cout << median << " " << L << " " << R << " 2\n";
					return false;
				} else if (L > median) {
					cost += L;
				}
			}

			// cout << cost << " ";
		}
		cout << "\n";
		// cout << median << " " << cost << "\n";

		return cost <= tot;
	};

	int lo = 0, hi = inf;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (ok(mid)) {
			ans = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	// assert(~ans);
	cout << ans << "\n\n\n";
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
		solve();
}
