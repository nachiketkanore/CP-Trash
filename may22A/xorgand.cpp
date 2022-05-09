/**
 *    Author: Nachiket Kanore
 *    Created: Sunday 08 May 2022 05:38:04 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int pref[32][N + 1];
		memset(pref, 0, sizeof(pref));
		auto get_len = [](int u) {
			int ret = 0;
			while (u > 0) {
				ret++;
				u >>= 1;
			}
			return ret;
		};
		FOR(i, 1, N) {
			int u;
			cin >> u;
			int len = get_len(u);
			pref[len][i]++;
		}
		FOR(i, 1, N) {
			FOR(j, 0, 31) {
				pref[j][i] += pref[j][i - 1];
			}
		}
		int Q;
		cin >> Q;
		while (Q--) {
			int L, R, X;
			cin >> L >> R >> X;
			int len = get_len(X);
			cout << (R - L + 1) - (pref[len][R] - pref[len][L - 1]) << '\n';
		}
	}
	return 0;
}
