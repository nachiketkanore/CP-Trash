/*
Author: Nachiket Kanore
Created: Saturday 17 October 2020 03:53:44 PM IST
(ツ) Mind is everything: muscle, pieces of rubber. All that I am, I am because of my mind.
*/
#include <cassert>
#include <iostream>

#define sz(x) (int)(x.size())
#define FOR(i, L, R) for (int i = (L); i <= (R); i++)
using namespace std;

const int N = 2e7 + 5, inf = 1e18;

int spf[N + 2];
int cnt[N + 2];

void pre() {
	FOR(i, 1, N) spf[i] = i;

	FOR(i, 2, N) if (spf[i] == i) {
		for (int j = 2 * i; j <= N; j += i) {
			if (spf[j] == j) {
				spf[j] = i;
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	pre();

	int NUMERATOR = 20000000;
	int DENOMINATOR = 15000000;

	FOR(i, 1, NUMERATOR) {
		int val = i;
		while (val > 1) {
			int p = spf[val];
			while (val % p == 0) {
				cnt[p]++;
				val /= p;
			}
		}
		assert(val == 1);
	}

	FOR(i, 1, DENOMINATOR) {
		int val = i;
		while (val > 1) {
			int p = spf[val];
			while (val % p == 0) {
				cnt[p]--;
				val /= p;
			}
		}
		assert(val == 1);
	}

	FOR(i, 1, NUMERATOR - DENOMINATOR) {
		int val = i;
		while (val > 1) {
			int p = spf[val];
			while (val % p == 0) {
				cnt[p]--;
				val /= p;
			}
		}
		assert(val == 1);
	}

	long long ans = 0;
	FOR(i, 1, N) {
		assert(cnt[i] >= 0);
		ans += 1LL * cnt[i] * i;
	}
	cout << ans;
}
