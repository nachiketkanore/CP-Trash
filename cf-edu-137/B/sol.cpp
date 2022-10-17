/**
 *    Author: Nachiket Kanore
 *    Created: Monday 17 October 2022 08:14:56 PM IST
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

int ans[100];

void solve() {
	int N;
	cin >> N;
	ans[0] = 1;
	ans[N - 1] = 2;
	int val = 3;
	FOR(i, 1, N - 2) {
		ans[i] = val++;
	}
	F0R(i, N) cout << ans[i] << " \n"[i == N - 1];
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
