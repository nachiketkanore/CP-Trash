/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 28 January 2024 01:28:27 PM IST
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
	vector<vector<int>> mat(N + 1, vector<int>(M + 1));
	FOR(i, 1, N) FOR(j, 1, M) cin >> mat[i][j];

	function<bool(int)> check = [&](int L) -> bool {
		vector<vector<int>> pref(N + 1, vector<int>(M + 1));
		FOR(i, 1, N) FOR(j, 1, M) {
			pref[i][j] = (mat[i][j] >= L) + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
		FOR(i, 1, N) FOR(j, 1, M) {
			int ni = i + L - 1, nj = j + L - 1;
			if (ni > N || nj > M)
				continue;
			int sum = pref[ni][nj];
			sum -= pref[ni][j - 1];
			sum -= pref[i - 1][nj];
			sum += pref[i - 1][j - 1];
			if (sum == L * L)
				return true;
		}

		return false;
	};

	int lo = 1, hi = min(N, M);
	int answer = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			answer = mid;
		} else {
			hi = mid - 1;
		}
	}

	assert(~answer);
	cout << answer << '\n';
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
