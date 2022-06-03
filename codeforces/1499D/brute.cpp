/**
 *    Author: Nachiket Kanore
 *    Created: Friday 03 June 2022 01:17:32 PM IST
 **/
#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

const int MAX = 3e7;

int spf[MAX + 1];

void init() {
	for (int i = 2; i <= MAX; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j <= MAX; j += i)
				if (spf[j] == 0)
					spf[j] = i;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();

	int T;
	cin >> T;

	while (T--) {
		int c, d, x;
		cin >> c >> d >> x;

		auto solve = [&](int g) {
			assert(x % g == 0);
			if ((x / g + d) % c)
				return 0;
			int K = (x / g + d) / c;

			int cnt = 1;
			while (K > 1) {
				int p = spf[K];
				while (K % p == 0)
					K /= p;
				cnt *= 2;
			}
			return cnt;
		};

		int64_t ans = 0;
		for (int d = 1; d * d <= x; d++) {
			if (x % d == 0) {
				ans += solve(d);
				if (x / d != d)
					ans += solve(x / d);
			}
		}

		cout << ans << '\n';
	}

	return 0;
}
