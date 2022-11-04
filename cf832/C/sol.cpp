/**
 *    Author: Nachiket Kanore
 *    Created: Friday 04 November 2022 09:54:08 PM IST
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
	// game theory :(
	int N;
	cin >> N;
	int u;
	cin >> u;
	int mn = 2e9;
	F0R(i, N - 1) {
		int x;
		cin >> x;
		mn = min(mn, x);
	}
	cout << (u > mn ? "Alice" : "Bob") << '\n';
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
