/**
 *    Author: Nachiket Kanore
 *    Created: Monday 18 April 2022 09:32:52 PM IST
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
	int A[N + 1];
	A[0] = 0;
	FOR(i, 1, N) {
		cin >> A[i];
		A[i] += A[i - 1];
	}
	auto f = [&](int L, int R) {
		if (L > R)
			return int(0);
		return A[R] - A[L - 1];
	};
	int ans = -1e18;
	FOR(i, 1, N) {
		FOR(j, i + 1, N) {
			FOR(k, j + 1, N) {
				ans = max(ans,
				f(1, i - 1) - f(i + 1, j - 1) - f(j + 1, k - 1) + f(k + 1, N));
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
