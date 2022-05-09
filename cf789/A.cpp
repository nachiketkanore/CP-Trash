/**
 *    Author: Solve Machine
 *    Created: Sunday 08 May 2022 08:03:40 PM IST
 **/
#include <bits/stdc++.h>

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, has = 0;
	cin >> N;
	vector<int> f, a;
	while (N--) {
		int u;
		cin >> u;
		a.push_back(u);
		if (u) {
			f.push_back(u);
		} else {
			has = 1;
		}
	}
	if (has) {
		cout << sz(f) << '\n';
	} else {
		bool dup = false;
		FOR(i, 0, sz(a) - 1) {
			FOR(j, i + 1, sz(a) - 1) {
				dup |= a[i] == a[j];
			}
		}
		if (dup) {
			cout << sz(a) << '\n';
		} else {
			cout << 1 + sz(a) << '\n';
		}
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
