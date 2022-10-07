/**
 *    Author: Nachiket Kanore
 *    Created: Friday 07 October 2022 08:36:32 PM IST
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
	int L, R;
	cin >> L >> R;
	auto get = [](int N) {
		int root = (int)sqrtl(N);
		int rem = 0;
		int L = N + 1;
		int R = 1ll * (root + 1) * (root + 1) - 1;
		if (L <= R) {
			rem = R / root - (L - 1) / root;
		}
		return int(3) * root - rem;
	};
	cout << 1ll * get(R) - get(L - 1) << '\n';
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
