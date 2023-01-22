/**
 *    Author: Nachiket Kanore
 *    Created: Friday 23 September 2022 05:36:27 PM IST
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
	int A[N];
	F0R(i, N) cin >> A[i];
	int ans = 1e18;
	FOR(i, 0, N - 1) {
		FOR(j, i + 1, N - 1) {
			FOR(k, j + 1, N - 1) {
				vector<int> have = { A[i], A[j], A[k] };
				sort(ALL(have));
				ans = min(ans, have[2] - have[1] + have[1] - have[0]);
			}
		}
	}
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
