/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 12:09:48 PM IST
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
	int N, M;
	cin >> N >> M;
	int mat[N][M], mx[N][M], mn[N][M];
	F0R(i, N) F0R(j, M) cin >> mat[i][j];

	mx[0][0] = mn[0][0] = mat[0][0];
	FOR(j, 1, M - 1) {
		mx[0][j] = mat[0][j] + mx[0][j - 1];
		mn[0][j] = mat[0][j] + mn[0][j - 1];
	}
	FOR(i, 1, N - 1) {
		mx[i][0] = mat[i][0] + mx[i - 1][0];
		mn[i][0] = mat[i][0] + mn[i - 1][0];
	}
	FOR(i, 1, N - 1) FOR(j, 1, M - 1) {
		mx[i][j] = mat[i][j] + max(mx[i - 1][j], mx[i][j - 1]);
		mn[i][j] = mat[i][j] + min(mn[i - 1][j], mn[i][j - 1]);
	}

	if ((N - 1 + M - 1 + 1) % 2) {
		cout << "NO\n";
	} else {
		assert(mn[N - 1][M - 1] % 2 == 0);
		assert(mx[N - 1][M - 1] % 2 == 0);
		assert(mn[N - 1][M - 1] <= mx[N - 1][M - 1]);
		if (mx[N - 1][M - 1] < 0 || mn[N - 1][M - 1] > 0)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
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
