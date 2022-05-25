/**
 *    Author: Nachiket Kanore
 *    Created: Wednesday 25 May 2022 11:47:59 AM IST
 **/
#include "bits/stdc++.h"

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

using namespace std;

void solve() {
	int N, a = 0, b = 0;
	cin >> N;
	while (N--) {
		int u;
		cin >> u;
		a = max(a, u);
	}
	int M;
	cin >> M;
	while (M--) {
		int u;
		cin >> u;
		b = max(b, u);
	}

	if (a > b) {
		cout << "Alice\nAlice\n";
	} else if (b > a) {
		cout << "Bob\nBob\n";
	} else {
		cout << "Alice\nBob\n";
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
