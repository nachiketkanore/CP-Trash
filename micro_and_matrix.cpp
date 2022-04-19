/**
 *    Author: Nachiket Kanore
 *    Created: Tuesday 19 April 2022 04:14:02 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N;
	cin >> N;
	vector<vector<int>> mat(N + 1, vector<int>(N + 1));
	vector<vector<int>> pref(N + 1, vector<int>(N + 1));
	FOR(i, 1, N) FOR(j, 1, N) {
		cin >> mat[i][j];
		pref[i][j] = mat[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
	}
	auto get_sum = [&](int r1, int r2, int c1, int c2) {
		return pref[r2][c2] - pref[r2][c1 - 1] - pref[r1 - 1][c2] + pref[r1 - 1][c1 - 1];
	};
	int ans = -1;
	FOR(i, 1, N) {
		FOR(j, 1, N) {
			int lo = 1, hi = min(N - i + 1, N - j + 1);
			int best = -1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				int r1 = i, c1 = j;
				int r2 = i + mid - 1, c2 = j + mid - 1;
				int want = mat[i][j] * mid * mid;
				if (get_sum(r1, r2, c1, c2) == want) {
					best = mid;
					lo	 = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			assert(~best);
			ans = max(ans, best);
		}
	}
	assert(~ans);
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
