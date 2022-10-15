/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 15 October 2022 05:31:01 PM IST
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
	int M, N, P;
	cin >> M >> N >> P;
	--P;
	int A[M][N];
	F0R(i, M) {
		F0R(j, N) {
			cin >> A[i][j];
		}
	}
	int ans = 0;
	F0R(j, N) {
		int best = 0;
		F0R(i, M) best = max(best, A[i][j]);
		ans += max(int(0), best - A[P][j]);
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	FOR(tc, 1, T) {
		cout << "Case #" << tc << ": ";
		solve();
	}

	return 0;
}
