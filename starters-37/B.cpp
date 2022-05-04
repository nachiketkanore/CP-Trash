/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 04 May 2022 07:54:07 PM IST
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
	int c[2];
	c[0] = c[1] = 0;
	F0R(i, N) {
		int u;
		cin >> u;
		c[u]++;
	}
	FOR(turn, 1, N - 1) {
		if (turn & 1) {
			// ALICE
			if (c[0] && c[1]) {
				c[0]--;
				c[1]--;
				c[1]++;
			} else if (c[1] >= 2) {
				c[1]--;
				c[1]--;
				c[1]++;
			} else if (c[0] >= 2) {
				c[0]--;
				c[0]--;
				c[0]++;
			} else
				assert(false);
		} else {
			// BOB
			if (c[0] && c[1]) {
				c[0]--;
				c[1]--;
				c[0]++;
			} else if (c[0] >= 2) {
				c[0]--;
				c[0]--;
				c[0]++;
			} else if (c[1] >= 2) {
				c[1]--;
				c[1]--;
				c[1]++;
			} else
				assert(false);
		}
	}
	assert(c[0] + c[1] == 1);
	if (c[0] == 1)
		cout << "0\n";
	else
		cout << "1\n";
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
