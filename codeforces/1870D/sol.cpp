/**
 *    Author: Nachiket Kanore
 *    Created: Thursday 22 February 2024 11:27:27 PM IST
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

const int _ = 2e5 + 5;
int N, K, C[_], ans[_];

void solve() {
	cin >> N;
	FOR(i, 1, N) cin >> C[i];
	cin >> K;
	int c_min = C[1], c_min_len = 1;
	FOR(i, 1, N) {
		if (C[i] <= c_min) {
			c_min = C[i];
			c_min_len = i;
		}
	}
	int max_first = K / c_min;
	FOR(i, 1, c_min_len) ans[i] = max_first;

	int farthest = -1;
	int max_second = -1;
	FOR(i, 1, N) {
		int have = min(K, c_min + (K % c_min));
		if (C[i] <= have) {
			farthest = i;
			max_second = max(max_second, have / C[i]);
		}
	}

	FOR(i, c_min_len + 1, farthest) {
		ans[i] = max_second;
	}
	if (max_second > max_first) {
		FOR(i, 1, farthest) ans[i] = max_second;
	}

	FOR(i, 1, N) cout << ans[i] << " \n"[i == N];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
