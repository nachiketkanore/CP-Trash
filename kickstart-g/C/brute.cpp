/**
 *    Author: Nachiket Kanore
 *    Created: Saturday 15 October 2022 05:51:56 PM IST
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

const int MX = 5e5 + 5;
int N, A[MX], pref[MX];

void solve() {
	cin >> N;
	FOR(i, 1, N) {
		cin >> A[i];
		pref[i] = pref[i - 1] + A[i];
	}
	int ans = 0;
	FOR(L, 1, N) {
		FOR(R, L, N) {
			if (pref[R] - pref[L - 1] < 0) {
				break;
			}
			ans += pref[R] - pref[L - 1];
		}
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
