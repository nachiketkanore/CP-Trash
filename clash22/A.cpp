/**
 *    Author: Nachiket Kanore
 *    Created: Friday 15 April 2022 09:01:38 AM IST
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
	string S;
	cin >> S;
	const string want = "credenz";
	int ans = 0;
	int pi = -1;
	F0R(i, N) {
		int j = i + sz(want) - 1;
		if (j < N) {
			if (S.substr(i, sz(want)) == want) {
				// cerr << i << ' ' << j << '\n';
				ans += (i - pi) * (N - j);
				pi = i;
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
