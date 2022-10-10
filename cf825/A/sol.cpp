/**
 *    Author: Nachiket Kanore
 *    Created: Monday 10 October 2022 08:05:56 PM IST
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

void solve() {
	int N;
	cin >> N;
	int A[N], B[N];
	F0R(i, N) {
		cin >> A[i];
	}
	int c01 = 0, c10 = 0;
	F0R(i, N) {
		cin >> B[i];
		if (A[i] ^ B[i]) {
			if (A[i] == 1 && B[i] == 0) {
				c10++;
			} else if (A[i] == 0 && B[i] == 1) {
				c01++;
			} else {
				assert(false);
			}
		}
	}
	int ans = 0;
	if (c10 > 0 && c01 > 0) {
		ans = 1;
		int rem = min(c01, c10);
		c01 -= rem;
		c10 -= rem;
	}
	ans += c10 + c01;
	cout << ans << '\n';
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
