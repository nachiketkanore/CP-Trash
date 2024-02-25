/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 25 February 2024 11:56:02 AM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
#include "debug.h"
#else
#define see(...) ;
#endif

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, u, ans = 0, val;
	cin >> N;
	map<int, int> counter;
	F0R(i, N) {
		cin >> u;
		val = u;
		int mask = 1;
		for (int d = 2; d * d <= u; d++) {
			if (u % d == 0) {
				int cnt = 0;
				while (u % d == 0)
					u /= d, cnt ^= 1;
				if (cnt)
					mask *= d;
			}
		}
		if (u != 1)
			mask *= u;
		ans += counter[mask];
		ans += counter[0];
		if (val == 0) {
			counter[0]++;
		} else {
			counter[mask]++;
		}
	}
	cout << ans;

	return 0;
}
